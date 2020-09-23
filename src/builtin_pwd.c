#include "../includes/minishell.h"

/*
** builtin_pwd: get current working directory path using getcwd().
** if getcwd() fails, it returns -1 and pwd prints error msg.
** if success, pwd prints the path of current working directory.
*/
void	builtin_pwd(void)
{
	char	buf[MAXPATHLEN];
	char	*ptr;

	if (!(ptr = getcwd(buf, MAXPATHLEN)))
	{
		write(2, "pwd: Failed to get path. Check the buffer size.\n", 48);
		return ;
	}
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
}
