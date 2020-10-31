/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:10:01 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/31 17:04:09 by yshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_error_msg(char *cmd, char *msg, int exit_status,
							char **full_cmd)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(".\n", 2);
	set_res(exit_status);
	if (full_cmd != NULL)
		free(*full_cmd);
}

void		set_exe_argv(char *full_cmd, char **arg_list, char ***exe_argv)
{
	char	**result;
	int		len;
	int		idx;

	len = ft_len_doublestr(arg_list) + 1;
	result = (char **)ft_calloc(sizeof(char *), (len + 1));
	result[0] = ft_strdup(full_cmd);
	idx = 0;
	while (++idx < len)
		result[idx] = ft_strdup(arg_list[idx - 1]);
	*exe_argv = result;
}

void		run_another_program(char **full_cmd, t_command *cmd)
{
	pid_t	pid;
	char	**exe_argv;

	pid = fork();
	signal(SIGINT, (void *)sig_execve_handler);
	signal(SIGQUIT, (void *)sig_execve_handler);
	if (pid == 0)
	{
		if (cmd->idx != 0)
			close(g_pipes[cmd->idx * 2 - 1]);
		set_exe_argv(cmd->cmd, cmd->arg_list, &exe_argv);
		execve(*full_cmd, exe_argv, g_envp);
		ft_free_doublestr(&exe_argv);
	}
	else if (pid < 0)
	{
		ft_putstr_fd("error: fork fails.\n", 2);
		set_res(1);
	}
	if (cmd->idx != 0)
		close(g_pipes[cmd->idx * 2 - 1]);
	free(*full_cmd);
}

void		cmd_execve(t_command *cmd)
{
	int		flag;
	char	**path_list;
	char	*full_cmd;

	set_res(0);
	if (!(path_list = parse_path_list()))
	{
		print_error_msg(cmd->cmd, "command not found", 127, NULL);
		return ;
	}
	full_cmd = NULL;
	flag = get_cmd_run_flag(cmd->cmd, &full_cmd);
	if (flag == -1)
		flag = get_cmd_run_flag_with_path(cmd->cmd, path_list, &full_cmd);
	ft_free_doublestr(&path_list);
	if (flag == 0)
		run_another_program(&full_cmd, cmd);
	else if (flag == 1)
		print_error_msg(cmd->cmd, "command not found", 127, NULL);
	else if (flag == 2)
		print_error_msg(cmd->cmd, "is a directory", 126, &full_cmd);
	else if (flag == 3)
		print_error_msg(cmd->cmd, "Permission denied", 126, &full_cmd);
}
