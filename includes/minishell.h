#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <sys/param.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef	struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

t_env	*g_env_list;

void	builtin_pwd(void);
void	builtin_cd(char *line, char *ptr, char *buffer);
void	builtin_echo(char *arg);

void	free_double_pointer(char **args);

/*
**	pre_process_line.c
*/
int		process_line(char *line);

#endif
