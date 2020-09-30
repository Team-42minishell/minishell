#include "../includes/minishell.h"

int		exec_butlin(char *line)
{
	char	*arg;
	char	*buffer[MAXPATHLEN];
	char	*value;
	// 환경변수
	if (ft_strncmp(line, "cd", 2) == 0)
		builtin_cd(line, value, buffer);
	else if (ft_strncmp(line, "echo", 4) == 0)
		builtin_echo(arg);
	else if (ft_strncmp(line, "pwd", 3) == 0)
		builtin_pwd();
}
int		has_semicolon(char *line)
{

}

int		has_pipe(char *line)
{

}

char	**preprocess(char *line)
{
	char	**split_data;
	char	*tmp;
	int		i;

	split_data = ft_split(line, ';');
	i = -1;
	while (split_data[++i])
	{
		if ((tmp = ft_strtrim(split_data[i], " ")) == NULL || tmp[i] == '\0')
			return ft_putstr("strtrim errror\n");
		free(split_data[i]);
		split_data[i] = tmp;
	}
	// 세미콜론 에러 체크 필요

	free(line);
	return (split_data);
}

int		process_line(char *line)
{
	int		i;
	char	**split_data;

	split_data = preprocess(line);
	i = -1;
	while (split_data[++i])
	{
		// 파이프가 있는 경우
		if (has_pipe(split_data[i]))
		{

		}
		// 세미 콜론이 있는 경우
		if (has_semicolon(split_data[i]))
		{
			ft_split(line, ';');
		}
		
		if (!exec_dollar(split_data[i]) && !exec_butlin(split_data[i]))
			exec_otehrs(split_data[i]);
	}
}