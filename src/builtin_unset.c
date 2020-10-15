#include "../includes/minishell.h"

/*
** move_data_to_g_env_list: move data from original array
** to g_env_list(reduced array size).
*/

void	move_data_to_g_env_list(char *key, int num_envs, t_env **orig_env_list)
{
	int		idx;
	int		idx2;

	idx = -1;
	idx2 = 0;
	while (++idx < num_envs)
	{
		if (ft_strncmp(key, (*orig_env_list)[idx].key, ft_strlen(key)) == 0
				&& key[ft_strlen(key)] == '\0')
		{
			free((*orig_env_list)[idx].key);
			free((*orig_env_list)[idx].value);
			continue ;
		}
		g_env_list[idx2].key = ft_strdup((*orig_env_list)[idx].key);
		g_env_list[idx2].value = (*orig_env_list)[idx].value == NULL ?
			NULL : ft_strdup((*orig_env_list)[idx].value);
		free((*orig_env_list)[idx].key);
		free((*orig_env_list)[idx].value);
		idx2++;
	}
	g_env_list[idx2].key = NULL;
	g_env_list[idx2].value = NULL;
	free((*orig_env_list));
}

/*
** is_arg_in_env_list: find the key in g_env_list.
** if it is, return 1. otherwise, return 0.
*/

int		is_arg_in_env_list(char *key, int num_envs)
{
	int		idx;

	idx = -1;
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, key, ft_strlen(key)) == 0
				&& key[ft_strlen(key)] == '\0')
			break ;
	if (idx == num_envs)
		return (1);
	return (0);
}

/*
** make_new_env_list_unset: make new array for env_list to run unset command.
** first, find the key that is same as 'unset' arg.
** if so, the function will return. otherwise, make new env list reduced size
** and move datas to new env list.
*/

void	make_new_env_list_unset(char *key, int num_envs)
{
	t_env	*orig_env_list;

	if (is_arg_in_env_list(key, num_envs) == 1)
		return ;
	orig_env_list = g_env_list;
	if (!(g_env_list = (t_env*)malloc(sizeof(t_env) * (num_envs))))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		orig_env_list = NULL;
		set_exit_status(1);
		return ;
	}
	move_data_to_g_env_list(key, num_envs, &orig_env_list);
}

/*
** builtin_unset: when the command is 'unset', this function is started.
** this function find arg as environmenet and unset the environment.
** if there is no environment same as arg, nothing will be happened.
*/

void	builtin_unset(char *line)
{
	int		idx;
	char	**arg_list;

	set_exit_status(0);
	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		set_exit_status(1);
		return ;
	}
	if (arg_list[1] == NULL)
	{
		free_double_pointer(arg_list);
		return ;
	}
	idx = 0;
	while (arg_list[++idx])
		make_new_env_list_unset(arg_list[idx], get_number_envs());
	free_double_pointer(arg_list);
}
