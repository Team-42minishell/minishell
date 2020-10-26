#include "libft.h"

int		ft_is_number(char *str)
{
	if (!str || !(*str))
		return (0);
	while (*str && *str >= 48 && *str <= 57)
		str++;
	return (*str == '\0');
}
