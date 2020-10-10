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

t_env			*g_env_list;

void			builtin_pwd(void);
void			builtin_cd(char *line);
void			builtin_echo(char *arg);
void			builtin_env();
void			builtin_export(char *line);
void			builtin_unset(char *line);

/*
**	parse_line.c
*/
char			**parse_line(char *line);
/*
**	parse_quote.c
*/
int				find_quote(char *line);
char			*make_newline(char *line, int str_len);
/*
**	exec_cmds.c
*/
int				exec_buitlin(char *line);
/*
**	utils.c
*/
void			free_double_pointer(char **args);
int				two_ptr_size(char **ptr);
/*
**	utils_env.c
*/
char			*find_value(char *key);
/*
**  builtin_export.c
*/
int		does_exist_env_oldpwd(void);
void	print_env_list(void);
int		get_parsing_idx(char *arg);
void	convert_empty_string_to_null(char **value);
int		get_number_envs(void);
/*
**  builtin_export2.c
*/
int		does_exist_same_env(char **key, char **value, int num_envs);
void	make_new_env_list(char **key, char **value, int num_envs);
void	set_env(char *arg);
void	builtin_export(char *line);
#endif
