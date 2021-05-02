/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:27:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:33:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*select_rotate(t_main *m, char *op)
{
	if (ft_strcmp(op, ROTATE_A) == 0)
		return (rotate(m->a, NO_PRINT));
	if (ft_strcmp(op, ROTATE_B) == 0)
		return (rotate(m->b, NO_PRINT));
	if (ft_strcmp(op, ROTATE_AB) == 0)
	{
		rotate(m->a, NO_PRINT);
		rotate(m->b, NO_PRINT);
		return ("");
	}
	if (ft_strcmp(op, REV_ROTATE_A) == 0)
		return (rev_rotate(m->a, NO_PRINT));
	if (ft_strcmp(op, REV_ROTATE_B) == 0)
		return (rev_rotate(m->b, NO_PRINT));
	if (ft_strcmp(op, REV_ROTATE_AB) == 0)
	{
		rev_rotate(m->a, NO_PRINT);
		rev_rotate(m->b, NO_PRINT);
		return ("");
	}
	return (NULL);
}

static char		*select_push(t_main *m, char *op)
{
	if (ft_strcmp(op, PUSH_A) == 0)
		return (push(m->a, m->b, NO_PRINT));
	if (ft_strcmp(op, PUSH_B) == 0)
		return (push(m->b, m->a, NO_PRINT));
	return (NULL);
}

static char		*select_swap(t_main *m, char *op)
{
	if (ft_strcmp(op, SWAP_A) == 0)
		return (swap(m->a, NO_PRINT));
	if (ft_strcmp(op, SWAP_B) == 0)
		return (swap(m->b, NO_PRINT));
	if (ft_strcmp(op, SWAP_AB) == 0)
	{
		swap(m->a, NO_PRINT);
		swap(m->b, NO_PRINT);
		return ("");
	}
	return (NULL);
}

static char		*select_op(t_main *m, char *op)
{
	if (op[0] == 's')
		return (select_swap(m, op));
	if (op[0] == 'p')
		return (select_push(m, op));
	if (op[0] == 'r')
		return (select_rotate(m, op));
	return (NULL);
}

int				execute(t_main *m, char *op)
{
	if (!(check_op(op)) || !(select_op(m, op)))
		return (0);
	if (m->opt->d || m->opt->v)
	{
		if (m->opt->d)
			usleep(SLEEP_TIME);
		print_stacks(*m, m->size_max, op);
	}
	return (1);
}
