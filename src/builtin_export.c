#include "../includes/minishell.h"

/*
** does_exist_env_oldpwd: find environment 'OLDPWD'.
** if it exists, return 1, otherwise, return 0.
*/

int		does_exist_env_oldpwd(void)
{
	int		idx;

	idx = -1;
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, "OLDPWD", 6) == 0
				&& g_env_list[idx].key[6] == 0)
			return (1);
	return (0);
}

/*
** print_env_list: print env list to declare env another place.
** if key of env is '_', don't print that.
** if there is no 'OLDPWD' as a key, this func prints just 'OLDPWD'
** without value. Like this, "declare -x OLDPWD".
*/

void	print_env_list(void)
{
	int		idx;

	idx = -1;
	while (g_env_list[++idx].key)
	{
		if (ft_strncmp(g_env_list[idx].key, "_", 1) == 0
				&& g_env_list[idx].key[1] == 0)
			continue ;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(g_env_list[idx].key, 1);
		if (g_env_list[idx].value == NULL)
		{
			ft_putstr_fd("\n", 1);
			continue ;
		}
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(g_env_list[idx].value, 1);
		ft_putstr_fd("\"\n", 1);
	}
}

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
			break ;
	if (idx == 0)
	{
		ft_putstr_fd("error: export: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (-1);
	}
	return (idx);
}

/*
** convert_empty_string_to_null: this function convert "" into NULL.
*/

void	convert_empty_string_to_null(char **value)
{
	char	*tmp;

	if (ft_strncmp(*value, "", 1) == 0)
	{
		tmp = *value;
		*value = NULL;
		free(tmp);
	}
}

/*
** get_number_envs: return the number of environments.
*/

int		get_number_envs(void)
{
	int		idx;

	idx = -1;
	while (g_env_list[++idx].key)
		;
	return (idx);
}
