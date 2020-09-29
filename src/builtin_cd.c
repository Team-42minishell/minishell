#include "../includes/minishell.h"

/*
**	1. 루트 디렉토리 (/), 절대경로 이동 (완)
**	2. 한 단계 상위 디렉토리 (..), 상대 경로 이동 (완)
**	3. 홈 디렉토리(~), 홈 디렉토리 이동 (미완)
**	4. 이전 디렉토리 (-) (미완)
**
**	line을 입력 받은 것을 사용해서 원하는 디렉토리로 이동한다.
**	chdir에 line을 입력하면 원하는 디렉토리로 이동하고, 0을 반환한다.
**	디렉토리가 없으면 -1이 반환
*/
void		builtin_cd(char *line, char *ptr, char *buffer)
{
	int		ret;

	ret = chdir(line);
	if (ret == 0)
	{
		ptr = getcwd(buffer ,MAXPATHLEN);
		if (ptr == NULL)
			ft_putstr_fd(strerror(errno), 1);
	}
	else if (ret == -1)
	{
		ft_putstr("cd: ");
		ft_putstr_fd(strerror(errno), 1);
		ft_putstr(" ");
		ft_putstr(line);
		ft_putstr("\n");
		errno = 0;
	}
	
}