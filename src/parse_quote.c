#include "../includes/minishell.h"

/*
**	문자열 맨앞과 맨뒤의 quote제거
**	문자열 제거한 문자열 주소 return
*/
char	*make_newline(char *line, int location)
{
	char	*new_line;
	int		str_len;

	str_len = location - 1;
	new_line = ft_calloc(sizeof(char), str_len + 1);
	ft_strlcpy(new_line, line + 1, str_len + 1);
	return (new_line);
}
/*
**	1. quote 체크
**	2. 문자열 맨앞과 맨뒤가 둘러 싸여져 있는지 체크한다.
**	3. 싸여져 있다면 뒤쪽 quote 위치값 반환, 아니면 0 반환
**	4. 예외처리 exit
*/
int		find_quote(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (line[0] == '\'')
	{
		if (line[len - 1] == '\'')
			return (len - 1);
		// 에러 처리 토의
		else
		{
			// 쉘은 quote를 입력 받으려고 한다.
			ft_putstr_fd("quote error\n", 1);
			exit(0);
		}
	}
	else if (line[0] == '\"')
	{
		if (line[len - 1] == '\"')
			return (len - 1);
		// 에러 처리 토의
		else
		{
			ft_putstr_fd("quote error\n", 1);
			exit(0);
		}
	}
	return (0);
}