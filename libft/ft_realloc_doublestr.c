#include "libft.h"
#include <stdio.h>

char	**ft_realloc_doublestr(char ***strs_ref, char *item)
{
	char	**ret;
	char	**strs;
	int		len;

	strs = *strs_ref;
	if (!item)
		return (strs);
	len = ft_len_doublestr(strs) + 2;
	if (!(ret = (char **)ft_calloc(sizeof(char *), len--)))
		return (0);
	ret[--len] = ft_strdup(item);
	while (len--)
		if (!(ret[len] = ft_strdup(strs[len])))
			return (0);
	*strs_ref = ret;
	ft_free_doublestr(&strs);
	return (ret);
}
