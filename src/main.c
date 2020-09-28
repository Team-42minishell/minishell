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

			if (ft_strncmp(line, "cd", 2) == 0)
			{
				builtin_cd(line + 3, value, buffer);
			}
			else
			{
				ft_putstr(line);
				ft_putchar_fd('\n', 1);
			}
			

			ft_putstr("catshell@");
			ft_putstr_fd(buffer, 1);
			ft_putstr(" ");
			free(line);
		}
		free(line);
	}
	return (1);
}

int			main()
{
	print_prompt();

	return (0);
}