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
# include "types.h"
# include "macro.h"


typedef	struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

t_env			*g_env_list;
int				g_exit_status;
int				*g_pipes;
int				g_res;
int				g_maxfd;
int				g_fd;

void			builtin_pwd(void);
void			builtin_cd(char *line);
void			builtin_echo(char *arg);
void			builtin_env();
void			builtin_export(char *line);
void			builtin_unset(char *line);
void			builtin_exit(char *line);

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
void			set_exit_status(int status);
/*
**	utils_env.c
*/
char			*find_value(char *key);
int				get_number_envs(void);
/*
**  builtin_export.c
*/
int				does_exist_env_oldpwd(void);
void			print_env_list(void);
int				get_parsing_idx(char *arg);
void			convert_empty_string_to_null(char **value);
/*
**  builtin_export2.c
*/
int				does_exist_same_env(char **key, char **value, int num_envs);
void			set_env_list_last_data(char *key, char *value, int idx);
void			make_new_env_list(char **key, char **value, int num_envs);
void			set_env(char *arg);
void			builtin_export(char *line);

/*
**	tokenizer.c
*/
char			**tokenizer(char *line);
/*
**	memory.c
*/
char			**ft_realloc_double_str(char ***strs_ref, char *item);
int				ft_free_str(char **str);
/*
**	lexer.c
*/
int				lexer(char **tokens);
char			type(char **tokens, int idx);
int				token_in(char **tokens, t_lexer *lex, char *format);
t_bool			is_valid_token(char **tokens, t_lexer *lex);
t_bool			check_seq(char **tokens, t_lexer *lex);
/*
**	utils_string.c
*/
int				right_qoute(char *src);
int				right_bracket(char *src);
/*
**	parser.c
*/
t_table			*parser (char **tokens);
void			parse(char **tokens, t_lexer *lexer, t_parser *parser, t_table *table);
void			create_job(t_parser *parser, t_table *table);
/*
**	utils_get_parser.c
*/
t_table			*get_last_table(t_table *table);
t_job			*get_last_job(t_table *table);
t_redir			*get_last_redir(t_table *table);
/*
**	utils_set_parser.c
*/
void	set_command_arg(char **tokens, t_lexer *lexer, t_table *table);
void	set_command_cmd(char **tokens, t_lexer *lexer, t_parser *parser, t_table *table);
void	set_redir_file(char **tokens, t_lexer *lexer, t_table *table);
/*
**	execute
*/
void	execute_table(t_table	*table);
/*
**	pwd
*/
void		cmd_pwd(void);
/*
**	cd
*/
void	cmd_cd(t_command *command);

/*
**	utils.free
*/
void	free_redir_list(t_redir *redir);
void	free_job_list(t_job *job);
void	free_tables(t_table *table);
#endif
