#include "../includes/minishell.h"

void	convert_res(char **ret, char *str, int *i, int first)
{
	char	*val;
	int		j;

	val = (first) ? ft_itoa(g_res) : ft_strdup("0");
	j = (str[*i + 1] == '{') ? *i + 3 : *i + 1;
	*i = 0;
	while (val && val[*i])
		ft_realloc(ret, val[(*i)++]);
	*i = j;
	ft_free_str(&val);
}

void	convert_env(char **ret, char *str, int *i, int first)
{
	char	*name;
	char	*val;
	char	end;
	int		j;
	t_bool	bracket;

	if (str[*i + 1] == '?' || (str[*i + 1] == '{' && str[*i + 2] == '?'))
		return (convert_res(ret, str, i, first));
	j = *i + 1;
	if (!str[j])
		return ;
	bracket = (str[j] == '{') ? TRUE : FALSE;
	j += (bracket) ? 1 : 0;
	end = (bracket) ? '}' : ' ';
	name = 0;
	printf("%d\n", ft_strlen(str));
	while (str[j] && str[j] != end && !ft_is_set(str[j], "\'\""))
		ft_realloc(&name, str[j++]);
	if (!str[j] || end == ' ')
		j--;
	val = find_value(name);
	*i = 0;
	while (val && val[*i])
		ft_realloc(ret, val[(*i)++]);
	ft_free_str(&name);
	*i = j;
}

void	convert(char **src, int first)
{
	int		i;
	int		opened;
	char	*str;
	char	*ret;

	i = 0;
	opened = 0;
	str = *src;
	if (!(ret = (char *)ft_calloc(sizeof(char), 1)))
		return ;
	while (str[i])
	{
		if (open_handle(&opened, str[i]))
			;
		else if (opened != '\'' && str[i] == '$'
		&& str[i + 1] && !ft_is_set(str[i + 1], " \'\""))
			convert_env(&ret, str, &i, first);
		else if (str[i] < 0)
			ft_realloc(&ret, str[i] * -1);
		else
			ft_realloc(&ret, str[i]);
		i++;
	}
	ft_free_str(&str);
	*src = ret;
}

void	convert_job(t_job *job, int first)
{
	int		i;
	t_redir	*redir;

	if (job->command.cmd)
		convert(&job->command.cmd, first);
	i = -1;
	if (job->command.arg_list)
		while (job->command.arg_list[++i])
			convert(&job->command.arg_list[i], first);
	if (!job->redir_list)
		return ;
	redir = job->redir_list;
	while (redir)
	{
		if (redir->sign)
			convert(&redir->sign, first);
		if (redir->arg)
			convert(&redir->arg, first);
		redir = redir->next;
	}	
}

void	converter(t_table *table)
{
	t_job	*job;
	int		first;

	first = TRUE;
	job = table->job_list;
	while (job)
	{
		convert_job(job, first);
		job = job->next;
		first = FALSE;
	}
	return ;
}