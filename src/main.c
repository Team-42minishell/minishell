#include "../includes/minishell.h"

#define MAX_PATH 100
#define LF 10

/*
**	buffer에는 절대경로가 저장되어 ㅇㅆ다.
*/
int			print_prompt()
{
	char	buffer[MAX_PATH];
	char	*value;
	char	*line;
	int		ret;

	value = getcwd(buffer, MAX_PATH);

	if (value != 0)
	{
		ft_putstr("catshell@");
		ft_putstr_fd(buffer, 1);
		ft_putstr(" ");

		while ((ret = get_next_line(0, &line)))
		{
			if (ret == -1)
				printf("get_next_line error\n");

			ft_putstr(line);
			ft_putchar_fd('\n', 1);
			free(line);
	
			ft_putstr("catshell@");
			ft_putstr_fd(buffer, 1);
			ft_putstr(" ");
		}
		free(line);
	}
	return (1);
}

int			main()
{
	printf("hello world\n");

	print_prompt();
	return (0);
}