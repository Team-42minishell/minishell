#include "../includes/minishell.h"
/*
int		check_right(char **str, char **format)
{
	int		n;
	
	n = 1;
	while ((*format[n]) && (*format[n]) != ']')
		n++;
	if (!((*format)[n]))
		return (0);
	n = n - 1;
	if (ft_strcmp(*str, (*format + 1), n) != 0)
	{
		if (*())
	}	
}
*/
void		handling_other(char **str, char **format)
{
	char	c;
	char	duple;

	c = *(*format);
	duple = 0;
	if (!check_char(str, format))
		*format = *format + 1;
	if (*(*format) == '+')
		duple = 1;
	if (*(*format) == '?' && *(*format + 1) == '+')
		duple = 1;
	while (duple && c == ' ' && ft_is_space(*(*str)))
		*str = *str + 1;
	while (duple && c == 'c' && ft_is_alpha(*(*str)))
		*str = *str + 1;
	while (duple && c == 'd' && ft_is_num(*(*str)))
		*str = *str + 1;
	while (duple && c == '*' && ft_is_print(*(*str)) && !ft_is_space(*(*str)))
		*str = *str + 1;
	while (ft_is_set(*(*format), "?+"))
		*format = *format + 1;
}

int		check_string(char **str, char **format)
{
	if (!check_char(str, format))
		return (0);
	*format = *format - 1;
	while (check_char(str, format))
		*format = *format - 1;
	*format = *format + 1;
	while (ft_is_set(*(*format), "?+"))
		*format = *format + 1;
	return (1);
}

int		check_char(char **str, char **format)
{
	char	c;

	c = *(*format);
	if (c == ' ' && !ft_is_space(*(*str)))
		return (0);
	if (c == 'c' && !ft_is_alpha(*(*str)))
		return (0);
	if (c == 'd' && !ft_is_num(*(*str)))
		return (0);
	if (c == '*' && !ft_is_print(*(*str)))
		return (0);
	*str = *str + 1;
	*format = *format + 1;
	return (1);
}

int		ft_is_format(char *str, char *format)
{
	int		valid;

	valid = 1;
	while (*format && valid)
	{
		if (!ft_is_set(*format, "[cd* "))
			return (0);
	//	if (*format == '[')
		//	valid = check_right(&str, &format);
		if (!ft_is_set(*(format + 1), "?+"))
			valid = check_char(&str, &format);
		else if (*(format + 1) == '+' && *(format + 2) != '?')
			valid = check_string(&str, &format);
		else
			handling_other(&str, &format);
	}
	return ((!(str) && !(*format) && valid) ? 1 : 0);
	
}