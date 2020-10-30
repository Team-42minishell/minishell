/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:07:03 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 17:07:04 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			type(char **tokens, int idx)
{
	if (ft_strcmp(tokens[idx], "|") == 0)
		return (PIPE);
	if (ft_strcmp(tokens[idx], ";") == 0)
		return (SEMI);
	if (ft_strcmp(tokens[idx], ";;") == 0)
		return (DSEMI);
	if (ft_strcmp(tokens[idx], ">") == 0)
		return (GREATER);
	if (ft_strcmp(tokens[idx], ">>") == 0)
		return (DGREATER);
	if (ft_strcmp(tokens[idx], "<") == 0)
		return (LESS);
	if (ft_is_format(tokens[idx], " +"))
		return (SPACE);
	if (ft_is_format(tokens[idx], "d+"))
		return (NUMBER);
	return (ft_strcmp(tokens[idx], "\n") == 0 ? ENTER : STRING);
}

static	t_bool	check_seq(char **tokens, t_lexer *lex)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (lex->format[i][++j])
		{
			c = lex->format[i][j];
			if (lex->res == TRUE || lex->res == FALSE)
				break ;
			if ((i == 0 && (lex->idx - j - 1) < 0) \
			|| (i == 1 && (lex->idx + j + 1) >= lex->len))
				lex->res = (c == 'X') ? TRUE : FALSE;
			else if ((i == 0 && c != type(tokens, lex->idx - j - 1)) \
			|| (i == 1 && c != type(tokens, lex->idx + j + 1)))
				lex->res = (!ft_is_set(c, "W*")) ? FALSE : -1;
		}
		if (lex->res == FALSE)
			break ;
	}
	ft_free_doublestr(&lex->format);
	return (lex->res != FALSE);
}

int				token_in(char **tokens, t_lexer *lex, char *format)
{
	lex->i = -1;
	lex->seqs = ft_split(format, ',');
	lex->j = 0;
	while (lex->seqs[lex->j])
	{
		lex->format = ft_split(lex->seqs[lex->j], '-');
		lex->res = -1;
		if (check_seq(tokens, lex))
			return (ft_free_doublestr(&lex->seqs));
		lex->j++;
	}
	ft_free_doublestr(&lex->seqs);
	return (0);
}

static t_bool	is_valid_token(char **tokens, t_lexer *lex)
{
	if (lex->type == DSEMI)
		return (FALSE);
	if (lex->type == STRING && !right_quote(tokens[lex->idx]))
		return (FALSE);
	if (lex->type == STRING && !right_bracket(tokens[lex->idx]))
		return (FALSE);
	if (ft_is_set(lex->type, "GHL"))
		return (!token_in(tokens, lex, FRONT_REDIR));
	if (ft_is_set(lex->type, "F"))
		return (!token_in(tokens, lex, FRONT_REDIR_BACK_X));
	if (ft_is_set(lex->type, "NCS"))
		return (TRUE);
	if (lex->type != SEMI && token_in(tokens, lex, NO_BACK_ARG))
		return (FALSE);
	if (!token_in(tokens, lex, FRONT_ALNUM))
		return (FALSE);
	return (TRUE);
}

int				lexer(char **tokens)
{
	t_lexer		*lex;
	char		*error_token;

	if (!tokens || !(lex = ft_calloc(sizeof(t_lexer), 1)))
		return (0);
	lex->len = ft_len_doublestr(tokens);
	while (tokens[lex->idx])
	{
		lex->type = type(tokens, lex->idx);
		if (!is_valid_token(tokens, lex))
		{
			if (!ft_strcmp(tokens[lex->idx], "\n"))
				error_token = "new_line";
			else
				error_token = tokens[lex->idx];
			error_tokenizer(error_token, LEXER_ERROR, 258);
			free(lex);
			return (FALSE);
		}
		lex->idx++;
	}
	ft_free(lex);
	return (TRUE);
}
