#include "../includes/minishell.h"

int		exec_buitlin(char *line, char *value, char *buffer)
{
	//char	*arg;

	// 환경변수
	if (ft_strncmp(line, "cd", 2) == 0)
		builtin_cd(line + 3, value, buffer);
	else if (ft_strncmp(line, "pwd", 3) == 0)
		builtin_pwd();
	else
		return (0);
	//else if (ft_strncmp(line, "echo", 4) == 0)
	//	builtin_echo(arg);
	return (1);
}


int		split_size(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

char	**pre_process(char *line)
{
	char	**split_ptr;
	char	**res;
	char	*tmp;
	int		i;
	int		size;
	int		len;

	split_ptr = ft_split(line, ';');
	size = split_size(split_ptr);
	if ((res = ft_calloc(sizeof(char *), size + 1)) == NULL)
	{
		ft_putstr_fd("ft_calloc error\n", 1);
		return (0);
	}
	res[size] = 0;
	i = -1;
	while (split_ptr[++i])
	{
		if ((tmp = ft_strtrim(split_ptr[i], " ")) == NULL || tmp[0] == 0)
		{
			ft_putstr_fd("str_trim errror\n", 1);
			return (0);
		}
		len = 0;
		len = strlen(tmp);
		res[i] = ft_calloc(sizeof(char), len + 1);
		ft_strlcpy(res[i], tmp, len + 1);
		free(tmp);
	}
	free_double_pointer(split_ptr);
	// 세미콜론 에러 체크 필요
	return (res);
}

int		process_line(char *line, char *value, char *buffer)
{
	int		i;
	char	**ptr_data;

	ptr_data = pre_process(line);
	i = -1;
	while (ptr_data[++i])
	{
		// 파이프가 있는 경우
		/*
		if (has_pipe(ptr_data[i]))
		{

		}
		// 세미 콜론이 있는 경우
		if (has_semicolon(ptr_data[i]))
		{
			ft_split(line, ';');
		}
		
		if (!exec_dollar(ptr_data[i]) && !exec_butlin(ptr_data[i]))
			exec_otehrs(ptr_data[i]);
			*/
		exec_buitlin(ptr_data[i], value, buffer);
	}
	free_double_pointer(ptr_data);
	return (1);
}