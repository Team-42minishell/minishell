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
# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "types.h"
# include "macro.h"

char			**g_envp;
int				*g_pipes;
int				g_res;
int				g_maxfd;
int				g_fd;

/*
**	utils_env.c
*/
int				get_key_idx(char *key);
int				set_env(char *key, char *val);
char			*find_value(char *key);
/*
**	tokenizer.c
*/
char			**tokenizer(char *line);
/*
**	lexer.c
*/
int				lexer(char **tokens);
char			type(char **tokens, int idx);
int				token_in(char **tokens, t_lexer *lex, char *format);
/*
**	utils_string.c
*/
int				right_quote(char *src);
int				right_bracket(char *src);
/*
**	parser.c
*/
t_table			*parser (char **tokens);
void			parse(char **tokens, t_lexer *lexer, t_parser *parser,
						t_table *table);
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
void			set_command_arg(char **tokens, t_lexer *lexer, t_table *table);
void			set_command_cmd(char **tokens, t_lexer *lexer, t_parser *parser,
								t_table *table);
void			set_redir_file(char **tokens, t_lexer *lexer, t_table *table);
/*
**	execute
*/
void			execute_table(t_table	*table);
/*
**	converter
*/
void			converter(t_table *table);
/*
**	pwd
*/
void			cmd_pwd(void);
/*
**	cd
*/
void			cmd_cd(t_command *command);
/*
**	echo
*/
void			cmd_echo(t_command *cmd);
/*
**	env
*/
void			cmd_env(t_command *cmd);
/*
**	export
*/
void			cmd_export(t_command *cmd);
/*
**	unset
*/
void			cmd_unset(t_command *cmd);
/*
**	execve
*/
void			cmd_execve(t_command *cmd);
/*
**	execve2
*/
char			**parse_path_list(void);
int				get_cmd_run_flag(char *cmd, char **full_cmd);
char			*add_path_to_cmd(char *path, char *cmd);
int				get_cmd_run_flag_with_path(char *cmd, char **path_list,
										char **full_cmd);
/*
**	utils_free.c
*/
void			free_redir_list(t_redir *redir);
void			free_job_list(t_job *job);
void			free_tables(t_table *table);
/*
**	utils_converter.c
*/
int				open_handle(int *opened, char c);
/*
**	signal.c
*/
void			sig_handler(int signo);
void			sig_execve_handler(int signo);
/*
**	exit.c
*/
void			cmd_exit(t_command *command);
/*
**	error.c
*/
void			error_builtin(char *cmd, char *arg, char *msg);
void			error_execute(char *error_token, char *msg, int res);
void			error_tokenizer(char *error_token, char *msg, int res);
/*
**	setting.c
*/
void			set_res(int res);
/*
**	ft_is_format.c
*/
int				ft_is_format(char *str, char *format);
int				check_char(char **str, char **format);
void			handling_other(char **str, char **format);

/*
**	utils_fd.c
*/
int				get_fd(t_redir *redir);
void			save_standard_fd(t_table *table);
void			redirect_stdout_fd(t_table *table);
void			restore_standard_fd(t_table *table);
void			close_fd_and_pipes(void);
/*
**	utils_pipe.c
*/
int				*make_pipes(t_job *job);
void			dup_pipe(t_job *job, int idx);
#endif
