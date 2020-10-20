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
** error msg
*/
# define LEXER_ERROR		"syntax error near unexpected token `"
#endif
