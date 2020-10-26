#include "libft.h"

int		ft_is_num(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}