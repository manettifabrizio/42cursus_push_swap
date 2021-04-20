/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:43:33 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 17:39:35 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

#define		NO_PRINT		0
#define		A				1
#define		B				2

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
# define	KO				"\e[0;31m\e[1mKO\e[0m"

typedef struct 	s_options
{
	int			v;
	int			o;
	int			c;
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
}				t_main;

int				create_stacks(char **av, t_main *s);

// SORTING
int				three_to_five(t_main *s);
int				chunks();

// OPERATIONS
int				execute(t_main *s, char *op);
int				swap(t_stack *s, int type);
int				push(t_stack *s1, t_stack *s2, int type);
int				rotate(t_stack *s, int type);
int				rev_rotate(t_stack *s, int type);

// UTILS
void			print_stacks(t_main m, t_stack a, t_stack b);
void			stack_scale(t_stack *s);
void			stack_del_one(t_stack *s);
int				stack_is_sort(t_stack *s);
int				find_min(int *a, size_t size);
int				find_max(int *a, size_t size);
int				min_pos(int *a, int size);
int				is_already_sort(int *a, size_t size);

// ERRORS
int				error(t_main *s);
int				check_stack(char *s);
int				check_dup(int *a, size_t size);
int				check_op(char *s);