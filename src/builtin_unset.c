#include "../includes/minishell.h"

void	make_new_env_list2(char *key, int num_envs)
{
	int		idx;
	int		idx2;
	t_env	*orig_env_list;

	idx = -1;
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, key, ft_strlen(key)) == 0 && key[ft_strlen(key)] == '\0')
			break ;
	if (idx == num_envs)
		return ;
	orig_env_list = g_env_list;
	if (!(g_env_list = (t_env*)malloc(sizeof(t_env) * (num_envs))))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		orig_env_list = NULL;
		return ;
	}
	idx = -1;
	idx2 = 0;
	while (++idx < num_envs)
	{
		if (ft_strncmp(key, orig_env_list[idx].key, ft_strlen(key)) == 0
				&& key[ft_strlen(key)] == '\0')
		{
			free(orig_env_list[idx].key);
			free(orig_env_list[idx].value);
			continue ;
		}
		g_env_list[idx2].key = ft_strdup(orig_env_list[idx].key);
		g_env_list[idx2].value = orig_env_list[idx].value == NULL ?
			NULL : ft_strdup(orig_env_list[idx].value);
		free(orig_env_list[idx].key);
		free(orig_env_list[idx].value);
		idx2++;
	}
	g_env_list[idx2].key = NULL;
	g_env_list[idx2].value = NULL;
	free(orig_env_list);
}

void	builtin_unset(char *line)
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
		free_double_pointer(arg_list);
		return ;
	}
	idx = 0;
	while (arg_list[++idx])
		make_new_env_list2(arg_list[idx], get_number_envs());
	free_double_pointer(arg_list);
}
