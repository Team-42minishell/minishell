/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:04:23 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 21:25:14 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	process_line(char *line)
{
	char	**tokens;
	t_table	*table;
	t_table	*first_table;

	tokens = tokenizer(line);
	ft_free_str(&line);
	if (!lexer(tokens) || !(table = parser(tokens)))
	{
		ft_free_doublestr(&tokens);
		return (TRUE);
	}
	ft_free_doublestr(&tokens);
	first_table = table;
	while (table)
	{
		converter(table);
		execute_table(table);
		table = table->next;
	}
	free_tables(first_table);
	return (1);
}

void		display_prompt(void)
{
	ft_putstr_fd("catshell$ ", 1);
}

int			main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*new_line;

	if (argc != 1)
		argv[0] = NULL;
	g_res = 0;
	g_envp = (char **)ft_dup_doublestr(envp);
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	while (TRUE)
	{
		display_prompt();
		if (!get_next_line(0, &line))
		{
			close_fd_and_pipes();
			free(line);
			ft_putendl_fd("exit", 1);
			ft_free_doublestr(&g_envp);
			exit(0);
		}
		new_line = ft_strjoin(line, "\n");
		free(line);
		process_line(new_line);
	}
	return (g_res);
}
