/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:43:33 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/22 13:56:28 by fmanetti         ###   ########.fr       */
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

int				create_stacks(char **av, t_main *m);

// SORTING
int				three_to_five(t_main *m);
int				six_to_fifty(t_main *m, t_stack *a, t_stack *b, t_list *h);

// OPERATIONS
int				execute(t_main *s, char *op);
char			*swap(t_stack *s, int type);
char			*push(t_stack *s1, t_stack *s2, int type);
char			*rotate(t_stack *s, int type);
char			*rev_rotate(t_stack *s, int type);

// UTILS
void			print_stacks(t_main m, t_stack a, t_stack b);
void			stack_scale(t_stack *s);
void			stack_del_one(t_stack *s);
int				stack_is_sort(t_stack s);
int				find_min(t_stack s);
int				find_max(t_stack s);
int				min_pos(t_stack s);
int				is_already_sort(t_stack s);

// ERRORS
int				error(t_main *s);
int				check_stack(char *s);
int				check_dup(t_stack s);
int				check_op(char *s);