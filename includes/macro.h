/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:31:14 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/19 15:31:15 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*
**  bool
*/
# define TRUE   1
# define FALSE  0
# define NONE	0

/*
**  fd
*/
# define STDIN  0
# define STDOUT 1

/*
**  meta character
*/
# define PIPE       'P'
# define SEMI       'Y'
# define DSEMI      'Z'
# define GREATER    'G'
# define DGREATER   'H'
# define LESS       'L'
# define STRING  	'C'
# define ENTER   	'F'
# define SPACE		'S'
/*
**	meta characters pattern
*/
# define FRONT_REDIR		"G-*,SG-*,H-*,SH-*,L-*,SL-*,M-*,SM-*"
# define FRONT_REDIR_BACK_X	"G-X,SG-X,H-X,SH-X,L-X,SL-X,M-X,SM-X"
# define FRONT_EMP_REDIR	"EG-*,EH-*,EL-*,EM-*"
# define FRONT_ALNUM		"N-*,C-*,SN-*,SC-*"
# define BACK_REDIR			"*-G,*-SG,*-H,*-SH,*-L,*-SL,*-M,*-SM"
# define NO_BACK_ARG		"*-X,*-SX,*-F,*-SF"
# define BACK_X_GREAT		"*-G,*-H"
/*
** error msg
*/
# define NOT_PRINT_ASCII	"Failed print ascii art"
# define LEXER_ERROR		"syntax error near unexpected token `"
# define REDIR_AMBIGOUS		"ambiguous redirect"
# define NO_SUCH_ENTRY		"No such file or directory"
# define PERMISSION_DENIED	"permission denied"
# define FORK_FAILED		"Fork failed for new process"
# define NOT_CMD_FOUND		"command not found"
# define EXECUTE_DRECTORY	"is a directory"
# define TOO_MANY_ARG		": too many arguments"
# define FAIL_TO_GET_PATH	": Faild to get path, check 'PWD_BUFFER_SIZE'"
# define NUMERIC_REQUIRED	": numeric argument required"
# define INVALID_IDENTIFIER	"\': not a valid identifier"
#endif
