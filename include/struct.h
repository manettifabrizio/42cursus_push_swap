/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:51:37 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 22:54:25 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft/libft.h"

typedef struct 	s_options
{
	int			c;
	int			d;
	int			o;
	int			v;
}				t_opt;

typedef	struct	s_stack
{
	int			*arr;
	size_t		size;
}				t_stack;


typedef struct	s_main
{
	t_stack		*a;
	t_stack		*b;
	size_t		size_max;
	int			ops_nbr;
	t_opt		*opt;
	int			is_opt;
}				t_main;

#endif