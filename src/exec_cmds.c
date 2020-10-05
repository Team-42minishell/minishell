#include "../includes/minishell.h"

/*
**	문자열에서 명령어가 있으면 그것을 실행한다.
**
*/
int		exec_buitlin(char *line, char *current_path, char *buffer)
{
	//char	*arg;

	// 환경변수
	if (ft_strncmp(line, "cd", 2) == 0 && (line[2] == 0 || line[2] == ' '))
		builtin_cd(line + 3, current_path, buffer);
	else if (ft_strncmp(line, "pwd", 3) == 0 && (line[3] == 0 || line[3] == ' '))
		builtin_pwd();
	else if (ft_strncmp(line, "env", 3) == 0 && (line[3] == 0 || line[3] == ' '))
		builtin_env();
	else if (ft_strncmp(line, "echo", 4) == 0 && (line[4] == 0 || line[4] == ' '))
		builtin_echo(line);
	else
	{
		ft_putstr_fd("exec_builtin error\n", 1);
		return (0);
	}
	//else if (ft_strncmp(line, "echo", 4) == 0)
	//	builtin_echo(arg);
	return (1);
}
