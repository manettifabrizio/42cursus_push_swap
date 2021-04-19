/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:23 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 18:20:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				is_one_ops(int *a)
{
	if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		return (rev_rotate_a(a, 3));
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		return (rotate_a(a, 3));
	return (0);
}

static int				three(int *a)
{
	if (stack_is_sort(a, 3))
		return (1);
	if (!is_one_ops(a))
	{
		swap_a(a, 3);
		if (stack_is_sort(a, 3))
			return (1);
		is_one_ops(a);
	}
	return (1);
}

int				is_already_sort(int *a, int size)
{
	int		x, y;
	int		min;
	int		*tmp;

	tmp = malloc (size * sizeof(int));
	min = find_min(a, size);
	x = 0;
	while (a[x] != min)
		x++;
	if (x == size - 1)
		x = 0;
	else
		x++;
	y = 1;
	tmp[0] = min;
	while (a[x] != min)
	{
		tmp[y++] = a[x];
		if (x == size - 1)
			x = 0;
		else
			x++;
	}
	if (stack_is_sort(tmp, size))
	{
		free(tmp);	
		return (1);
	}
	free(tmp);
	return (0);
}

static int				min_pos(int *a, int size)
{
	int		x;
	int		min;

	x = 0;
	min = find_min(a, size);
	while (a[x] != min && x < size)
		x++;
	return (x);
}

static int				four_or_five(t_stack *s)
{
	int		min;
	int		max;

	min = find_min(s->a, s->size_a);
	max = find_max(s->a, s->size_a);
	while (s->size_a > 3 && !is_already_sort(s->a, s->size_a))
		push_b(s->b, s->a, &(s->size_b), &(s->size_a));
	if (s->size_a == 3)
		three(s->a);
	while (s->size_b > 0)
	{
		if (s->b[0] == max && s->a[0] == find_min(s->a, s->size_a))
			push_a(s->a, s->b, &(s->size_a), &(s->size_b));
		else if (s->b[0] < s->a[0] && s->b[0] < s->a[s->size_a - 1]
			&& s->a[0] == find_min(s->a, s->size_a))
			push_a(s->a, s->b, &(s->size_a), &(s->size_b));
		else if (s->b[0] < s->a[0] && s->b[0] > s->a[s->size_a - 1])
			push_a(s->a, s->b, &(s->size_a), &(s->size_b));
		else if (s->b[0] > s->a[0] && s->b[0] > s->a[s->size_a - 1]
			&& s->a[0] == find_min(s->a, s->size_a))
			push_a(s->a, s->b, &(s->size_a), &(s->size_b));
		else if (s->b[0] > s->a[0] && s->b[0] < s->a[1])
			rotate_a(s->a, s->size_a);
		else
			rev_rotate_a(s->a, s->size_a);
	}
	while (!(stack_is_sort(s->a, s->size_a)))
		if (min_pos(s->a, s->size_a) <= 2)
			rotate_a(s->a, s->size_a);
		else
			rev_rotate_a(s->a, s->size_a);
	return (1);
}

int				three_to_five(t_stack *s)
{
	if (s->size_max == 3)
		return (three(s->a));
	if (s->size_max == 4 || s->size_max == 5)
		return (four_or_five(s));
	return (0);	
}