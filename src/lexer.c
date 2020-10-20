#include "../includes/minishell.h"

char	type(char **tokens, int idx)
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
	if (ft_strcmp(tokens[idx], " ") == 0)
		return (SPACE);
	return (ft_strcmp(tokens[idx], "\n") == 0 ? ENTER : STRING);
}
/*
t_bool	check_seq(char **tokens, t_lexer *lex)
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
				break;
			if ((i == 0 && lex->idx - j - 1 < 0) || (i == 1 && lex->idx + j + 1) >= lex->len))
				lex->res = (c == 'X') ? TRUE : FALSE;
			else if ((i == 0 && c != type(tokens, lex->idx - j - 1)) || (i == 1 && c != type(tokens, lex->idx + j + 1)))
				lex->res = (!ft_is_set(c, "W*")) ? FALSE : -1;
		}
		if (lex -> res == FALSE)
			break;
	}
	free_double_pointer(lex->format);
	return (lex->res != FALSE);
}
*/
/*
int		token_in(char **tokens, t_lexer *lex, char *format)
{
	lex->i = -1;
	lex->seqs = ft_split(format, ",");
	lex->j = 0;
	while (lex->seqs[lex->j])
	{
		if (check_seq(tokens, lex))
		{
			free_double_pointer(lex->seqs);
			return 1;
		}
		lex->j++;
	}
	free_double_pointer(lex->seqs);
	
}
*/

t_bool	is_valid_token(char **tokens, t_lexer *lex)
{
	if (lex->type == DSEMI)
		return (FALSE);
	if (lex->type == STRING && !right_qoute(tokens[lex->idx]))
		return (FALSE);
	if (lex->type == STRING && !right_bracket(tokens[lex->idx]))
		return (FALSE);
	/*
	if (ft_is_set(lex->type, "GHL"))
		return (!token_in(tokens, lex, " "));
	if (ft_is_set(lex->type, "F"))
		return (!token_in(tokens, lex, " "));
	if (ft_is_set(lex->type, "NCS"))
		return (TRUE);
	*/
	return (TRUE);
}

int		lexer(char **tokens)
{
	t_lexer		*lex;
	char		*errror_tokens;

	if (!tokens || !(lex = ft_calloc(sizeof(t_lexer), 1)))
		return (0);
	lex -> len = two_ptr_size(tokens);
	while (tokens[lex->idx])
	{
		lex->type = type(tokens, lex->idx);
		printf("%s %c\n", tokens[lex->idx], lex->type);
		if (!is_valid_token(tokens, lex))
		{
			if (!ft_strcmp(tokens[lex->idx], "\n"))
				errror_tokens = "new_line";
			else
				errror_tokens = tokens[lex->idx];
			printf("error_token : %s\n", tokens[lex->idx]);
			free(lex);
			return (FALSE);
		}
		lex->idx++;
	}
	ft_free(lex);
	return (TRUE);
}