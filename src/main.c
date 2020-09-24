#include "../includes/minishell.h"

#define MAX_PATH 100

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