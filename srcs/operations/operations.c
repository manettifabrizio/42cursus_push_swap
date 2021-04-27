/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:36:37 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/27 14:23:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			*swap(t_stack *s, int type)
{
	if (s->size > 1)
		ft_swap(&(s->arr[0]), &(s->arr[1]));
	if (type == A)
		return (ft_strdup(SWAP_A));
	else if (type == B)
		return (ft_strdup(SWAP_B));
	return ("");
}

char			*push(t_stack *s1, t_stack *s2, int type)
{
	if (s2->size > 0)
	{
		stack_scale(s1);
		s1->arr[0] = s2->arr[0];
		stack_del_one(s2);
	}
	if (type == A)
		return (ft_strdup(PUSH_A));
	else if (type == B)
		return (ft_strdup(PUSH_B));
	return ("");
}

char			*rotate(t_stack *s, int type)
{
	int		i;
	int		tmp;

	if (s->size > 1)
	{
		tmp = s->arr[0];
		i = -1;
		while (++i < (int)(s->size - 1))
			s->arr[i] = s->arr[i + 1];
		s->arr[s->size - 1] = tmp;
	}
	if (type == A)
		return (ft_strdup(ROTATE_A));
	else if (type == B)
		return (ft_strdup(ROTATE_B));
	return ("");
}

char			*rev_rotate(t_stack *s, int type)
{
	int		i;
	int		tmp;

	if (s->size > 1)
	{
		tmp = s->arr[s->size - 1];
		i = s->size;
		while (--i > 0)
			s->arr[i] = s->arr[i - 1];
		s->arr[0] = tmp;
	}
	if (type == A)
		return (ft_strdup(REV_ROTATE_A));
	else if (type == B)
		return (ft_strdup(REV_ROTATE_B));
	return ("");
}