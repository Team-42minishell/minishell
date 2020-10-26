#include "../includes/minishell.h"

int		open_handle(int *opened, char c)
{
	int		ret;

	ret = 0;
	if (!(*opened) && ft_is_set(c, "\'\""))
	{
		*opened = c;
		ret = 1;
	}
	else if (*opened && *opened == c)
	{
		*opened = 0;
		ret = 1;
	}
	return (ret);
}