/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:23 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 17:55:02 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*is_one_ops(t_stack *s)
{
	if (s->arr[0] < s->arr[1] && s->arr[1] > s->arr[2] &&
		s->arr[2] < s->arr[0])
		return (rev_rotate(s, A));
	if (s->arr[0] > s->arr[1] && s->arr[1] < s->arr[2] &&
		s->arr[2] < s->arr[0])
		return (rotate(s, A));
	return (NULL);
}

static int		three(t_stack *s)
{
	char	*op;

	if (stack_is_sort(*s))
		return (1);
	if (!(op = is_one_ops(s)))
	{
		printf("%s\n", swap(s, A));
		if (stack_is_sort(*s))
			return (1);
		op = is_one_ops(s);
	}
	printf("%s\n", op);
	return (1);
}

static int		four_or_five(t_stack *a, t_stack *b)
{
	t_main m;
	int		min;
	int		max;

	m.size_max = a->size;
	min = find_min(*a);
	max = find_max(*a);
	while (a->size > 3)
		printf("%s\n", push(b, a, B));
	if (a->size == 3)
		three(a);
	while (!(stack_is_sort(*a) && b->size == 0))
	{
		if (((b->arr[0] < find_min(*a) && a->arr[0] == find_min(*a)) ||
			(b->arr[0] > find_max(*a) && a->arr[0] == find_min(*a)) ||
			(b->arr[0] < a->arr[0] && b->arr[0] > a->arr[a->size - 1]))
			&& b->size > 0)
			printf("%s\n", push(a, b, A));
		else if ((choose_rotation_b_a(b->arr[0], *a) && b->size > 0) ||
			min_pos(*a) <= (int)a->size / 2)
			printf("%s\n", rotate(a, A));
		else
			printf("%s\n", rev_rotate(a, A));
	}
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
