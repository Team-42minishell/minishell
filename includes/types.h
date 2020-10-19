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

#endif
