#include "libft.h"

int		ft_startswith(const char *str, const char *sub)
{
	int		i;

	i = 0;
	while (sub[i] != '\0' && str[i] == sub[i])
		i++;
	return (sub[i] == '\0');
}
