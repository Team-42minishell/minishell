#include "../includes/minishell.h"

void	builtin_pwd(void)
{
	char	buf[MAXPATHLEN];
	char	*ptr;

	ptr = getcwd(buf, MAXPATHLEN);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
}
