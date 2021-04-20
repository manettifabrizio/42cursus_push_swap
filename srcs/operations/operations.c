/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:36:37 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 17:37:50 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				swap(t_stack *s, int type)
{
	if (type == A)
		printf("%s\n", SWAP_A);
	else if (type == B)
		printf("%s\n", SWAP_B);
	if (s->size > 1)
		ft_swap(&(s->arr[0]), &(s->arr[1]));
	return (1);
}

int				push(t_stack *s1, t_stack *s2, int type)
{
	if (type == A)
		printf("%s\n", PUSH_A);
	else if (type == B)
		printf("%s\n", PUSH_B);
	if (!(s2->size))
		return (1);
	stack_scale(s1);
	s1->arr[0] = s2->arr[0];
	stack_del_one(s2);
	return (1);
}

int				rotate(t_stack *s, int type)
{
	int		i;
	int		tmp;

	if (type == A)
		printf("%s\n", ROTATE_A);
	else if (type == B)
		printf("%s\n", ROTATE_B);
	if (s->size > 1)
	{
		tmp = s->arr[0];
		i = -1;
		while (++i < (int)(s->size - 1))
			s->arr[i] = s->arr[i + 1];
		s->arr[s->size - 1] = tmp;
	}
	return (1);
}

int				rev_rotate(t_stack *s, int type)
{
	int		i;
	int		tmp;

	if (type == A)
		printf("%s\n", REV_ROTATE_A);
	else if (type == B)
		printf("%s\n", REV_ROTATE_B);
	if (s->size > 1)
	{
		tmp = s->arr[s->size - 1];
		i = s->size;
		while (--i > 0)
			s->arr[i] = s->arr[i - 1];
		s->arr[0] = tmp;
	}
	return (1);
}