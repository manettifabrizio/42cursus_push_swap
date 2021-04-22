/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:27:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/22 00:05:18 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		select_rotate(t_main *m, char *op)
{
	if (ft_strcmp(op, ROTATE_A) == 0)
		return (rotate(m->a, NO_PRINT));
	if (ft_strcmp(op, ROTATE_B) == 0)
		return (rotate(m->b, NO_PRINT));
	if (ft_strcmp(op, ROTATE_AB) == 0)
	{
		rotate(m->a, NO_PRINT);
		rotate(m->b, NO_PRINT);
		return (1);
	}
	if (ft_strcmp(op, REV_ROTATE_A) == 0)
		return (rev_rotate(m->a, NO_PRINT));
	if (ft_strcmp(op, REV_ROTATE_B) == 0)
		return (rev_rotate(m->b, NO_PRINT));
	if (ft_strcmp(op, REV_ROTATE_AB) == 0)
	{
		rev_rotate(m->a, NO_PRINT);
		rev_rotate(m->b, NO_PRINT);
		return (1);
	}
	return (0);
}

static int		select_push(t_main *m, char *op)
{
	if (ft_strcmp(op, PUSH_A) == 0)
		return (push(m->a, m->b, NO_PRINT));
	if (ft_strcmp(op, PUSH_B) == 0)
		return (push(m->b, m->a, NO_PRINT));
	return (0);
}

static int		select_swap(t_main *m, char *op)
{
	if (ft_strcmp(op, SWAP_A) == 0)
		return (swap(m->a, NO_PRINT));
	if (ft_strcmp(op, SWAP_B) == 0)
		return (swap(m->b, NO_PRINT));
	if (ft_strcmp(op, SWAP_AB) == 0)
	{
		swap(m->a, NO_PRINT);
		swap(m->b, NO_PRINT);
		return (1);
	}
	return (0);
}

static int		select_op(t_main *m, char *op)
{
	if (op[0] == 's')
		return (select_swap(m, op));
	if (op[0] == 'p')
		return (select_push(m, op));
	if (op[0] == 'r')
		return (select_rotate(m, op));
	return (0);
}

int				execute(t_main *m, char *op)
{
	if (!(check_op(op)))
		return (0);
	if (!(select_op(m, op)))
	{
		free(op);
		return (0);
	}
	if (m->opt->v)
	{
		printf("%s\n", op);
		print_stacks(*m, *(m->a), *(m->b));
	}
	free(op);
	// printf("size_a = %zu size_b = %zu size_max = %zu\n", m->a->size, m->b->size, m->size_max);
	return (1);
}