#include "../includes/minishell.h"

void		cmd_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 1024);
	if (!path)
	{
		ft_putstr_fd("fail cmd_pwd\n", 1);
		return ;
	}
	ft_putendl_fd(path, 1);
	ft_free_str(&path);
	return ;
}