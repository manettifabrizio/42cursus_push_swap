/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:43:33 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 11:46:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define	SWAP_A			"sa"
# define	SWAP_B			"sb"
# define	SWAP_AB			"ss"
# define	PUSH_A			"pa"
# define	PUSH_B			"pb"
# define	ROTATE_A		"ra"
# define	ROTATE_B		"rb"
# define	ROTATE_AB		"rr"
# define	REV_ROTATE_A	"rra"
# define	REV_ROTATE_B	"rrb"
# define	REV_ROTATE_AB	"rrr"

# define	ERROR			"\e[0;31m\e[1mError\n\e[0m"
# define	OK				"\e[0;32m\e[1mOK\e[0m"
# define	KO				"\e[0;31m\e[1mKO\n\e[0m"

typedef struct	s_stack
{
	int			*a;
	size_t		size_a;
	int			*b;
	size_t		size_b;
	size_t		size_max;
	size_t		ops_nbr;
}				t_stack;

int				create_stacks(char **av, t_stack *s);

// SORTING
int				three_to_five(t_stack *s);
int				chunks();

// OPERATIONS
int				execute(t_stack *s, char *op);
int				swap_a(int *a, size_t size);
int				swap_b(int *a, size_t size);
int				swap_ab(int *a, int *b, size_t size_a, size_t size_b);
int				push_a(int *a, int *b, size_t *size_a, size_t *size_b);
int				push_b(int *b, int *a, size_t *size_b, size_t *size_a);
int				rotate_a(int *a, size_t size);
int				rotate_b(int *a, size_t size);
int				rotate_ab(int *a, int *b, size_t size_a, size_t size_b);
int				rev_rotate_a(int *a, size_t size);
int				rev_rotate_b(int *a, size_t size);
int				rev_rotate_ab(int *a, int *b, size_t size_a, size_t size_b);

// UTILS
void			print_stacks(t_stack s);
void			stack_scale(int *stack, size_t *size);
void			stack_del_one(int *stack, size_t *size);
int				stack_is_sort(int *a, size_t size);
int				find_min(int *a, size_t size);
int				find_max(int *a, size_t size);
int				min_pos(int *a, int size);
int				is_already_sort(int *a, size_t size);

// ERRORS
int				error(t_stack *s);
int				check_stack(char *s);
int				check_dup(int *a, size_t size);
int				check_op(char *s);