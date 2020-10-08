#include "../includes/minishell.h"

/*
** does_exist_same_env: find if there is same environment.
** if it exists, return 1. otherwise, return 0.
*/

int		does_exist_same_env(char **key, char **value, int num_envs)
{
	int		idx;
	char	*temp;

	idx = -1;
	temp = NULL;
	while (++idx < num_envs)
	{
		if (ft_strncmp(*key, g_env_list[idx].key, ft_strlen(*key)) == 0
				&& (*key)[ft_strlen(*key) + 1] == '\0')
		{
			temp = g_env_list[idx].value;
			g_env_list[idx].value = *value == NULL ? NULL : ft_strdup(*value);
			free(temp);
			free(*key);
			free(*value);
			return (1);
		}
	}
	return (0);
}

/*
** make_new_env_list: expand g_env_list.
*/

void	make_new_env_list(char **key, char **value, int num_envs)
{
	int		idx;
	t_env	*orig_env_list;

	orig_env_list = g_env_list;
	if (!(g_env_list = (t_env*)malloc(sizeof(t_env) * (num_envs + 2))))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		free(*key);
		free(*value);
		return ;
	}
	idx = -1;
	while (++idx < num_envs)
	{
		g_env_list[idx].key = ft_strdup(orig_env_list[idx].key);
		g_env_list[idx].value = orig_env_list[idx].value == NULL ?
			NULL : ft_strdup(orig_env_list[idx].value);
		free(orig_env_list[idx].key);
		free(orig_env_list[idx].value);
	}
	free(orig_env_list);
	g_env_list[idx].key = ft_strdup(*key);
	g_env_list[idx].value = *value == NULL ? NULL : ft_strdup(*value);
	free(*key);
	free(*value);
}

/*
** set_env: this func sets environment with arg by parsing key and value.
*/

void	set_env(char *arg)
{
	int		parsing_idx;
	char	*key;
	char	*value;
	int		num_envs;

	parsing_idx = get_parsing_idx(arg);
	if (parsing_idx == -1)
		return ;
	key = ft_substr(arg, 0, parsing_idx);
	value = ft_substr(arg, parsing_idx + 1, ft_strlen(arg));
	convert_empty_string_to_null(&value);
	num_envs = get_number_envs();
	if (does_exist_same_env(&key, &value, num_envs) == 1)
		return ;
	make_new_env_list(&key, &value, num_envs);
}

/*
** builtin_export: set env or print the list of env.
** if there is no export's arg, print env list.
** otherwise, set env with key and value.
** this func can set one or more arg at a time.
*/

void	builtin_export(char *line)
{
	int		idx;
	char	**arg_list;

	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		return ;
	}
	if (arg_list[1] == NULL)
	{
		print_env_list();
		free_double_pointer(arg_list);
		return ;
	}
	idx = 0;
	while (arg_list[++idx])
		set_env(arg_list[idx]);
	free_double_pointer(arg_list);
}
