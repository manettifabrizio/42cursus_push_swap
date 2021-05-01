/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 22:50:32 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_scale(t_stack *s)
{
	int		i;

	i = (int)(s->size);
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	(s->size)++;
}

void			stack_del_one(t_stack *s)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)(s->size))
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	(s->size)--;
}

int				stack_is_sort(t_stack s)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)s.size)
	{
		if (s.arr[i] > s.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}