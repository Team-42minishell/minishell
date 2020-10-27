#include "../includes/minishell.h"

/*
** get_parsing_idx: find index where '=' is.
** if '=' is at index 0, that means there is no key and occurs an error.
*/

int		get_parsing_idx(char *arg)
{
	int		idx;

	idx = -1;
	while (arg[++idx])
		if (arg[idx] == '=')
			return (idx);
	return (-1);
}

/*
** export_env: this func sets environment with arg by parsing key and value.
*/

int		export_env(char *arg)
{
	int		parsing_idx;
	char	*key;
	char	*value;

	if (arg == NULL || ft_is_num(arg[0]) || arg[0] == '=')
		return (FALSE);
	parsing_idx = get_parsing_idx(arg);
	if (parsing_idx == -1)
		return (TRUE);
	key = ft_substr(arg, 0, parsing_idx);
	value = ft_substr(arg, parsing_idx + 1, ft_strlen(arg));
	set_env(key, value);
	free(key);
	free(value);
	return (TRUE);
}

void	print_env_list(void)
{
	char	**env_list;
	int		idx;

	env_list = ft_dup_doublestr(g_envp);
	ft_sort_doublestr(env_list, 0, ft_len_doublestr(g_envp) - 1);
	idx = -1;
	while (env_list[++idx])
	{
		ft_putstr("declare -x ");
		ft_putstr(env_list[idx]);
		ft_putstr("\n");
	}
	free_double_pointer(env_list);
	set_res(0);
}

/*
** cmd_export: set env or print the list of env.
** if there is no export's arg, print env list.
** otherwise, set env with key and value.
** this func can set one or more arg at a time.
*/

void	cmd_export(t_command *cmd)
{
	int		idx;
	char	**arg_list;

	set_exit_status(0);
	if (!cmd->arg_list)
		print_env_list();
	else
	{
		idx = -1;
		while (cmd->arg_list[++idx])
		{
			if (export_env(cmd->arg_list[idx]) == FALSE)
				error_builtin("export", cmd->arg_list[idx], INVALID_IDENTIFIER);
		}
	}
}
