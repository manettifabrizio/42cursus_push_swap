/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:43:33 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/05 17:40:51 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define	ERROR		"\e[0;31m\e[1mError\n\e[0m"
# define	OK			"\e[0;32m\e[1mOK\n\e[0m"
# define	KO			"\e[0;31m\e[1mKO\n\e[0m"

typedef struct	s_stack
{
	int			*a;
	size_t		size_a;
	int			*b;
	size_t		size_b;
	size_t		size_max;
}				t_stack;


// INSTRUCTIONS
int				execute_instructions(t_stack *s, char *inst);
int				swap(int *a, size_t size);
int				push(int *a1, int *a2, size_t *size_a1, size_t *size_a2);
int				rotate(int *a, size_t size);
int				rev_rotate(int *a, size_t size);

// UTILS
void			stack_scale(int *stack, size_t *size);
void			stack_del_one(int *stack, size_t *size);
int				stack_is_sort(int *a, size_t size);

// ERRORS
int				error(t_stack *s);
int				check_stack(char *s);
int				check_dup(char **a);
int				check_inst(char *s);