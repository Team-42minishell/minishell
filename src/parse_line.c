#include "../includes/minishell.h"

/*
**	semicolon_syntax_error
**	세미콜론으로 인한 에러 처리
*/
int		semicolon_syntax_error(char	*line)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(line, " ");
	i = -1;
	if (tmp[0] == ';')
	{
		free(tmp);
		return (1);
	}
	while (tmp[++i])
	{
		if (tmp[i] == ';' && tmp[i + 1] == ';')
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}
/*
**	trim 한 데이터를 새로운 문자열 배열에 저장한다.
*/
void	save_parse_line(char **res, int index, char *line)
{
	int		len;

	len = ft_strlen(line);
	res[index] = ft_calloc(sizeof(char), len + 1);
	ft_strlcpy(res[index], line, len + 1);
}

char	**process_line(char *line)
{
	int		size;
	int		i;
	char	**split_ptr;
	char	**res;
	char	*trim;

	split_ptr = ft_split(line, ';');
	size = ft_len_doublestr(split_ptr);
	res = ft_calloc(sizeof(char *), size + 1);
	i = -1;
	while (split_ptr[++i])
	{
		if ((trim = ft_strtrim(split_ptr[i], " ")) == NULL || !(*trim))
		{
			free(trim);
			free_double_pointer(res);
			res = NULL;
			break;
		}
		save_parse_line(res, i, trim);
		free(trim);
	}
	free_double_pointer(split_ptr);
	free(line);
	return (res);
}
/*
**	세미콜론을 기준으로 문자열을 나눈다.
**	나눈 문자열에서 공백을 제거하고, 정제된 문자열의 주소값을 리턴해준다.
*/
char	**parse_line(char *line)
{
	char	**res;

	// 세미 콜론
	if (semicolon_syntax_error(line))
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		free(line);
		return (NULL);
	}
	res = process_line(line);
	return (res);
}