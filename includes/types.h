/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:30:50 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/19 15:31:33 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef int		t_bool;
/*
** tokenizer.c
*/
typedef struct	s_tokenizer
{
	int		idx;
	int		qidx;
	int		start;
	int		prev;
	char	quote;
}				t_tokenizer;
/*
**	lexer.c
*/
typedef struct	s_lexer
{
	char	**seqs;
	char	**format;
	char	type;
	int		len;
	int		idx;
	int		i;
	int		j;
	int		res;
}				t_lexer;
/*
**	parser.c
*/
typedef struct	s_parser
{
	int		command;
	int		fd;
}				t_parser;
/*
**	table structure with almost files
*/
typedef struct	s_redir
{
	char	*sign;
	char	*arg;
	int		fd;
	int		error;
	struct	s_redir	*next;
}				t_redir;

typedef struct	s_command
{
	char		*cmd;
	char		**arg_list;
	int			idx;
}				t_command;

typedef	struct	s_job
{
	struct	s_command	command;
	struct	s_redir		*redir_list;
	struct	s_job		*next;
}				t_job;

typedef struct	s_table
{
	struct s_job		*job_list;
	int					sep_type;
	int					fd[3];
	struct	s_table		*next;
}				t_table;
#endif
