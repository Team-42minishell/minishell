#include "../includes/minishell.h"

/*
**	crtl + c (EOF)가 입력될 때 까지 get_next_line을 실행하여
**  문자열을 입력받고, 입력 받은 문자열을 출력해주었다.
**	그래서 임시로 prompt 처럼 보이게 하였다.
*/
int			print_prompt()
{
	char	buffer[MAXPATHLEN];
	char	*value;
	char	*line;
	int		ret;

	value = getcwd(buffer, MAXPATHLEN);

	if (value != 0)
	{
		ft_putstr("catshell@");
		ft_putstr_fd(buffer, 1);
		ft_putstr(" ");

		while ((ret = get_next_line(0, &line)))
		{
			if (ret == -1)
				printf("get_next_line error\n");
			/*

			if (ft_strncmp(line, "cd", 2) == 0)
			{
				builtin_cd(line + 3, value, buffer);
			}
			else if (ft_strncmp(line, "env", 3) == 0 && line[3] == 0)
			{
				//for test
				int	idx = -1;
				while (g_env_list[++idx].key)
				{
					ft_putstr_fd(g_env_list[idx].key, 1);
					ft_putstr_fd("=", 1);
					ft_putstr_fd(g_env_list[idx].value, 1);
					ft_putstr_fd("\n", 1);
				}
			}
			else
			{
				ft_putstr(line);
				ft_putchar_fd('\n', 1);
			}
			

			ft_putstr("catshell@");
			ft_putstr_fd(buffer, 1);
			ft_putstr(" ");
			*/
			process_line(line);
			free(line);
		}
		free(line);
	}
	return (1);
}

/*
** parse_env: parse enviorment variables and define key and value to g_env_list.
*/

void		parse_env(char *envp[])
{
	char	**env_list;
	int		idx;

	idx = -1;
	while (envp[++idx])
		;
	if (!(g_env_list = (t_env*)malloc(sizeof(t_env) * idx + 1)))
	{
		ft_putstr_fd("error: can't allocate.\n", 2);
		exit(1);
	}
	idx = -1;
	while (envp[++idx])
	{
		if (!(env_list = ft_split(envp[idx], '=')))
		{
			ft_putstr_fd("error: can't allocate.\n", 2);
			exit(1);
		}
		g_env_list[idx].key = ft_strdup(env_list[0]);
		g_env_list[idx].value = ft_strdup(env_list[1]);
		free(env_list[0]);
		free(env_list[1]);
		free(env_list);
	}
}	

// int			main(int argc, char *argv[], char *envp[])
int		main()
{
	// it's not good. but because of gcc option, argc and argv are used.
	//if (argc != 1)
	//	argv[0] = NULL;

	//parse_env(envp);
	print_prompt();

	return (0);
}
