#include "../includes/minishell.h"

int		ft_free_str(char **str)
{
	if (!str || !(*str))
		return (0);
	free(*str);
	*str = 0;
	return (1);
}

char	**ft_realloc_double_str(char ***strs_ref, char *item)
{
	char	**ret;
	char	**strs;
	int		len;

	strs = *strs_ref;
	if (!item)
		return (strs);
	len = two_ptr_size(strs) + 2;
	if (!(ret = (char **)ft_calloc(sizeof(char *), len--)))
		return (0);
	ret[--len] = ft_strdup(item);
	while (len--)
		if (!(ret[len] = ft_strdup(strs[len])))
			return (0);
	*strs_ref = ret;
	free_double_pointer(strs);
	return (ret);
}