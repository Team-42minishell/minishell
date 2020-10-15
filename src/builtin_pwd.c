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
		ft_putstr_fd("pwd: Failed to get path. Check the buffer size.\n", 2);
		set_exit_status(1);
		return ;
	}
	ft_putstr_fd(ptr, 1);
	ft_putstr("\n");
	set_exit_status(0);
}
