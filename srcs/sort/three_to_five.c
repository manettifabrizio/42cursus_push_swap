/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:23 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/21 23:36:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_one_ops(t_stack *s)
{
	if (s->arr[0] < s->arr[1] && s->arr[1] > s->arr[2] &&
		s->arr[2] < s->arr[0])
		return (rev_rotate(s, A));
	if (s->arr[0] > s->arr[1] && s->arr[1] < s->arr[2] &&
		s->arr[2] < s->arr[0])
		return (rotate(s, A));
	return (0);
}

static int		three(t_stack *s)
{

	if (stack_is_sort(*s))
		return (1);
	if (!is_one_ops(s))
	{
		swap(s, A);
		if (stack_is_sort(*s))
			return (1);
		is_one_ops(s);
	}
	return (1);
}

static int		four_or_five(t_stack *a, t_stack *b)
{
	int		min;
	int		max;

	min = find_min(*a);
	max = find_max(*a);
	while (a->size > 3 && !(is_already_sort(*a)))
		push(b, a, B);
	if (a->size == 3)
		three(a);
	while (b->size > 0)
	{
		if ((b->arr[0] == max && a->arr[0] == find_min(*a)) ||
			(b->arr[0] == min && a->arr[0] == find_min(*a)) ||
			(b->arr[0] < find_min(*a) && b->arr[0] != min) ||
			(b->arr[0] > find_max(*a) && b->arr[0] != max) ||
			(b->arr[0] < a->arr[0] && b->arr[0] > a->arr[a->size - 1]))
			push(a, b, A);
		else if (b->arr[0] > a->arr[0] && b->arr[0] < a->arr[1])
			rotate(a, A);
		else
			rev_rotate(a, A);
	}
	while (!(stack_is_sort(*a)))
		if (min_pos(*a) <= 2)
			rotate(a, A);
		else
			rev_rotate(a, A);
	return (1);
}

int				three_to_five(t_main *m)
{
	if (m->size_max == 3)
		return (three(m->a));
	if (m->size_max == 4 || m->size_max == 5)
		return (four_or_five(m->a, m->b));
	return (0);
}
