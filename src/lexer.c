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
			//printf("formats : %s format : %c\n", lex->format[i], lex->format[i][j]);
			if (lex->res == TRUE || lex->res == FALSE)
				break;
			if ((i == 0 && (lex->idx - j - 1) < 0)
			||	(i == 1 && (lex->idx + j + 1) >= lex->len))
			{
				/*
				printf("hello x\n");
				if (i == 0 && (lex->idx - j - 1) < 0)
				{
					printf("char : %c, index : %d\n", c, lex->idx - j - 1);
				}
				else if (i == 1 && (lex->idx + j + 1) >= lex->len)
				{
					printf("char : %c, index: %d\n", c, lex->idx + j + 1);
				}
				*/
				lex->res = (c == 'X') ? TRUE : FALSE;
			}
			else if ((i == 0 && c != type(tokens, lex->idx - j -1 ))
			||	(i == 1 && c != type(tokens, lex->idx + j + 1)))
			{
				/*
				printf("hello w\n");
				if (i == 0)
				{
					printf("char : %c first : %d\n", c, lex->idx - j - 1);
				}
				else if (i == 1 && (lex->idx + j + 1) >= lex->len)
				{
					printf("char : %c, first : %d\n", c, lex->idx + j + 1);
				}
				*/
				lex->res = (!ft_is_set(c, "W*")) ? FALSE : -1;
			}
		}
		if (lex -> res == FALSE)
			break;
	}
	free_double_pointer(lex->format);
	return (lex->res != FALSE);
}
/*
**	type에 저장되어있는 meta character pattern에 맞는 문자열인지 분석한다.
*/
int		token_in(char **tokens, t_lexer *lex, char *format)
{
	lex->i = -1;
	lex->seqs = ft_split(format, ',');
	lex->j = 0;
	while (lex->seqs[lex->j])
	{
		lex->format = ft_split(lex->seqs[lex->j], '-');
		lex->res = -1;
		if (check_seq(tokens, lex))
		{
			free_double_pointer(lex->seqs);
			return 1;
		}
		lex->j++;
	}
	free_double_pointer(lex->seqs);
	return (0);
}
/*
**	token이 맞는지 type과, 패턴에 맞게 틀리는지 체크를한다.
*/
t_bool	is_valid_token(char **tokens, t_lexer *lex)
{
	if (lex->type == DSEMI)
		return (FALSE);
	if (lex->type == STRING && !right_qoute(tokens[lex->idx]))
		return (FALSE);
	if (lex->type == STRING && !right_bracket(tokens[lex->idx]))
		return (FALSE);
	// redir
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

int		lexer(char **tokens)
{
	t_lexer		*lex;
	char		*error_tokens;

	if (!tokens || !(lex = ft_calloc(sizeof(t_lexer), 1)))
		return (0);
	lex -> len = two_ptr_size(tokens);
	while (tokens[lex->idx])
	{
		lex->type = type(tokens, lex->idx);
		// printf("lexer : %s %c\n", tokens[lex->idx], lex->type);
		if (!is_valid_token(tokens, lex))
		{
			if (!ft_strcmp(tokens[lex->idx], "\n"))
				error_tokens = "new_line";
			else
				error_tokens = tokens[lex->idx];
			printf("error_token : %s\n", tokens[lex->idx]);
			free(lex);
			return (FALSE);
		}
		lex->idx++;
	}
	ft_free(lex);
	return (TRUE);
}