#include "libft.h"
#include <stdio.h>

char	**ft_remove_doublestr(char **str, int idx)
{
	char	**ret;
	int		len;
	int		i;
	int		j;

	len = ft_len_doublestr(str);
	if (!(ret = (char **)ft_calloc(sizeof(char *), len)))
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != idx && !(ret[j++] = ft_strdup(str[i])))
			return (0);
		i++;
	}
	ft_free_doublestr(&str);
	return (ret);
}
