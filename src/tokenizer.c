/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:31:35 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 16:31:41 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		token_init(t_tokenizer *tool)
{
	tool->idx = 0;
	tool->qidx = 0;
	tool->start = -1;
	tool->prev = 0;
	tool->quote = FALSE;
}

char			get_quote(char *line, int idx)
{
	char	quote;

	quote = 0;
	if (line[idx] == '\'')
		quote = '\'';
	else if (line[idx] == '\"')
		quote = '\"';
	return (quote);
}

int				get_end(char *line, t_tokenizer *tool)
{
	int		i;

	i = tool->idx;
	if (!line || tool->start == -1)
		return (FALSE);
	if (line[i] == tool->quote && tool->qidx != i)
		tool->quote = FALSE;
	if (!line[i + 1] || (!tool->quote && line[i] == '\n'))
		return (TRUE);
	if (!tool->quote && line[i + 1] == '\n')
		return (TRUE);
	if (tool->quote)
		return (FALSE);
	if (ft_is_space(line[i]))
		return (!(ft_is_space(line[i + 1])));
	if (ft_is_space(line[i + 1]))
		return (TRUE);
	if (ft_is_set(line[i], "><|;"))
	{
		if (line[i] != line[i + 1])
			return (TRUE);
		return ((tool->prev == line[i] && tool->start != i) ? TRUE : FALSE);
	}
	return (ft_is_set(line[i + 1], "><|;") ? TRUE : FALSE);
}

int				get_start(char *line, t_tokenizer *tool)
{
	int		i;

	i = tool->idx;
	if (!line || !line[i] || tool->quote)
		return (FALSE);
	if ((tool->quote = get_quote(line, i)))
		tool->qidx = i;
	if (line[i] == '\n')
		return (TRUE);
	if (ft_is_set(line[i], "><|;"))
	{
		if (tool->prev == line[i])
			return (FALSE);
		tool->prev = line[i];
		return (TRUE);
	}
	tool->prev = 0;
	if (!tool->idx)
		return (TRUE);
	if (ft_is_space(line[i]))
		return (ft_is_space(line[i - 1]) ? FALSE : TRUE);
	return (ft_is_space(line[i - 1]) || (ft_is_set(line[i - 1], "><|;")));
}

char			**tokenizer(char *line)
{
	t_tokenizer		tool;
	char			*token;
	char			**tokens;

	tokens = 0;
	token_init(&tool);
	while (line[tool.idx])
	{
		token = 0;
		if (get_start(line, &tool))
			tool.start = tool.idx;
		if (get_end(line, &tool))
		{
			token = ft_substr(line, tool.start, tool.idx - tool.start + 1);
			ft_realloc_doublestr(&tokens, token);
			ft_free_str(&token);
			tool.start = -1;
			tool.prev = 0;
		}
		tool.idx++;
	}
	return (tokens);
}
