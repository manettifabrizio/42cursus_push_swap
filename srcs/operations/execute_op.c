/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:27:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/16 01:23:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		select_rotate(t_stack *s, char *op)
{
	if (ft_strcmp(op, ROTATE_A) == 0)
		return (rotate_a(s->a, s->size_a));
	if (ft_strcmp(op, ROTATE_B) == 0)
		return (rotate_b(s->b, s->size_b));
	if (ft_strcmp(op, ROTATE_AB) == 0)
		return (rotate_ab(s->a, s->b, s->size_a, s->size_b));
	if (ft_strcmp(op, REV_ROTATE_A) == 0)
		return (rev_rotate_a(s->a, s->size_a));
	if (ft_strcmp(op, REV_ROTATE_B) == 0)
		return (rev_rotate_b(s->b, s->size_b));
	if (ft_strcmp(op, REV_ROTATE_AB) == 0)
		return (rev_rotate_ab(s->a, s->b, s->size_b, s->size_a));
	return (0);
}

static int		select_push(t_stack *s, char *op)
{
	if (ft_strcmp(op, PUSH_A) == 0)
		return (push_a(s->a, s->b, &(s->size_a), &(s->size_b)));
	if (ft_strcmp(op, PUSH_B) == 0)
		return (push_b(s->b, s->a, &(s->size_b), &(s->size_a)));
	return (0);
}

static int		select_swap(t_stack *s, char *op)
{
	if (ft_strcmp(op, SWAP_A) == 0)
		return (swap_a(s->a, s->size_a));
	if (ft_strcmp(op, SWAP_B) == 0)
		return (swap_b(s->b, s->size_b));
	if (ft_strcmp(op, SWAP_AB) == 0)
		return (swap_ab(s->a, s->b, s->size_a, s->size_b));
	return (0);
}

static int		select_op(t_stack *s, char *op)
{
	if (op[0] == 's')
		return (select_swap(s, op));
	if (op[0] == 'p')
		return (select_push(s, op));
	if (op[0] == 'r')
		return (select_rotate(s, op));
	return (0);
}

int				execute(t_stack *s, char *op)
{
	if (!(check_op(op)))
		return (0);
	if (!(select_op(s, op)))
	{
		free(op);
		return (0);
	}
	free(op);
	print_stacks(*s);
	return (1);
}