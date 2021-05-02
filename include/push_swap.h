/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:43:33 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:19:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <limits.h>
# include "struct.h"
# include "macros.h"

int				create_stacks(t_main *m, char **av);

int				choose_rotation_b_a(int n, t_stack s);
int				choose_rotation_a_b(int n, t_stack s);
int				three_to_five(t_main *m);
int				chunks(t_main *m, t_stack *a, t_stack *b, t_list **h);
t_stack			*create_chunks(t_main m, t_stack a);
void			optimize_rotation(t_list **h);

int				execute(t_main *m, char *op);
char			*swap(t_stack *s, int type);
char			*push(t_stack *s1, t_stack *s2, int type);
char			*rotate(t_stack *s, int type);
char			*rev_rotate(t_stack *s, int type);
int				debug_mode(t_main *m, char **a);

int				options(t_main *m, char *s);
void			print_stacks(t_main m, size_t size_max, char *op);
void			stack_scale(t_stack *s);
void			stack_del_one(t_stack *s);
int				stack_is_sort(t_stack s);
int				find_min(t_stack s);
int				find_max(t_stack s);
int				min_pos(t_stack s);
int				max_pos(t_stack s);
int				is_already_sort(t_stack s);
char			**add_elem_to_arr(char **a, char *op);
void			set_term_cano(struct termios *base_term);
void			set_term_noncano(void);

int				error(t_main *s);
char			**check_stack(char *s);
int				check_dup(t_stack s);
int				check_op(char *s);
void			free_all(t_main *m);

#endif
