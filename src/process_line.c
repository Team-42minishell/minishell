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


int		split_size(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

/*
**	세미콜론을 기준으로 문자열을 나눈다.
**	나눈 문자열에서 공백을 제거하고, 정제된 문자열의 주소값을 리턴해준다.
*/
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
		// exit(1);
		return (0);
	}
	res[size] = 0;
	i = -1;
	while (split_ptr[++i])
	{
		if ((tmp = ft_strtrim(split_ptr[i], " ")) == NULL)
		{
			ft_putstr_fd("str_trim errror1\n", 1);
			free_double_pointer(split_ptr);
			return (0);
		}
		len = ft_strlen(tmp);
		res[i] = ft_calloc(sizeof(char), len + 1);
		ft_strlcpy(res[i], tmp, len + 1);
		free(tmp);
	}
	free_double_pointer(split_ptr);
	// 세미콜론 에러 체크 필요
	return (res);
}

int		process_line(char *line, char *current_path, char *buffer)
{
	int		i;
	char	**ptr_data;

	if ((ptr_data = pre_process(line)) == NULL)
	{
		ft_putstr_fd("ptr_data_error1\n", 1);
		free_double_pointer(ptr_data);
		return (0);
	}
	else if (ptr_data[0] == NULL)
	{
		ft_putstr_fd("ptr_data_error2\n", 1);
		free_double_pointer(ptr_data);
		return (0);
	}
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
		exec_buitlin(ptr_data[i], current_path, buffer);
	}
	free_double_pointer(ptr_data);
	return (1);
}
