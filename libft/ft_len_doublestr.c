#include "libft.h"

int		ft_len_doublestr(char **str)
{
	int		idx;

	idx = 0;
	if (!str || !(*str))
		return (0);
	while (*str++)
		idx++;
	return (idx);
}
