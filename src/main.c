#include "../includes/minishell.h"

void		sig_handler(int signo)
{
	char	buffer[MAXPATHLEN];
	char	*current_path;

	if (signo == SIGINT)
	{
		current_path = getcwd(buffer, MAXPATHLEN);
		ft_putstr("\b\b  \b\b\n");
		ft_putstr("catshell@");
		ft_putstr_fd(buffer, 1);
		ft_putstr(" ");
		set_exit_status(1);
	}
	if (signo == SIGQUIT)
		ft_putstr("\b\b  \b\b");
}

/*
**	crtl + c (EOF)가 입력될 때 까지 get_next_line을 실행하여
**  문자열을 입력받고, 입력 받은 문자열을 출력해주었다.
**	그래서 임시로 prompt 처럼 보이게 하였다.
*/
int			print_prompt()
{
	//char	**new_line;
	char	buffer[MAXPATHLEN];
	char	*current_path;
	char	*line;
	int		ret;
	//int		i;

	current_path = getcwd(buffer, MAXPATHLEN);

	if (current_path != 0)
	{
		ft_putstr("catshell@");
		ft_putstr_fd(buffer, 1);
		ft_putstr(" ");

		while (1)
		{
			ret = get_next_line(0, &line);
			if (ft_strlen(line) == 0 && ret == 0)
				builtin_exit("exit");
			if (ret == -1)
				printf("get_next_line error\n");
			/*
			if ((new_line = parse_line(line)) != NULL)
			{
				i = -1;
				while (new_line[++i])
				{
					//ft_putstr("start : ");
					// ft_putstr_fd(new_line[i], 1);
					//ft_putstr("\n");
					exec_buitlin(new_line[i]);
				}
				free_double_pointer(new_line);
			}
			else
			{
				//ft_putstr("main error\n");
			}
			*/
			current_path = getcwd(buffer, MAXPATHLEN);
			ft_putstr("catshell@");
			ft_putstr_fd(buffer, 1);
			ft_putstr(" ");
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

	idx = two_ptr_size(envp);
	if (!(g_env_list = (t_env*)malloc(sizeof(t_env) * (idx + 2))))
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
		g_env_list[idx].value = env_list[1] == NULL ? "" : ft_strdup(env_list[1]);
		free_double_pointer(env_list);
	}
	g_env_list[idx].key = ft_strdup("OLDPWD");
	g_env_list[idx].value = NULL;
	g_env_list[idx + 1].key = NULL;
	g_env_list[idx + 1].value = NULL;
}	

int			process_line1(char *line)
{
	char	**tokens;
	t_table	*table;
	t_table	*first_table;

	tokens = tokenizer(line);
	ft_free_str(&line);
	if (!lexer(tokens) || !(table = parser(tokens)))
		return (TRUE);
	free_double_pointer(tokens);
	first_table = table;
	while (table)
	{
		converter(table);
		//printf("%s\n",table->job_list->command.cmd);
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

int			main(int argc, char *argv[], char *envp[])
{
	char	*line;
	// it's not good. but because of gcc option, argc and argv are used.
	if (argc != 1)
		argv[0] = NULL;

	g_exit_status = 0;
	parse_env(envp);
	/*
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	print_prompt();
	*/
	while (TRUE)
	{
		display_prompt();
		if (!get_next_line(0, &line))
			break;
		//printf("%d", ft_strlen(line));
		process_line1(line);
	}
	return (g_exit_status);
}
