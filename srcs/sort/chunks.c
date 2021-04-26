/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/26 17:08:49 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			add_elem_to_list(t_list **h, char *s)
{
	t_list	*new;

	if (!(new = ft_lstnew(s)))
		return (0);
	ft_lstadd_back(h, new);
	return (1);
}

static void		max_to_the_top(t_stack *b, t_list **h)
{
	int		max;
	int		pos;

	pos = max_pos(*b);
	max = find_max(*b);
	if (pos > (int)(b->size / 2))
	{
		while (b->arr[0] != max)
			add_elem_to_list(h, rev_rotate(b, B));
	}
	else
		while (b->arr[0] != max)
			add_elem_to_list(h, rotate(b, B));
}

static void		push_to_b(t_stack *a, t_stack *b, t_list **h)
{
	int		min;
	int		max;

	min = find_min(*a);
	max = find_max(*a);
	if ((a->arr[0] == max && b->arr[0] == find_min(*b)) ||
			(a->arr[0] == min && b->arr[0] == find_min(*b)) ||
			(a->arr[0] < find_min(*a) && a->arr[0] != min) ||
			(a->arr[0] > find_max(*a) && a->arr[0] != max) ||
			(a->arr[0] < b->arr[0] && a->arr[0] > b->arr[b->size - 1]))
			add_elem_to_list(h, push(b, a, B));
		else if (a->arr[0] > b->arr[0] && a->arr[0] < b->arr[1])
			add_elem_to_list(h, rotate(b, B));
		else
			add_elem_to_list(h, rev_rotate(b, B));
}

static int		find_to_push(t_stack a, int start, int end)
{
	int		i;
	int		first;
	int		second;

	i = 0;
	first = -1;
	second = -1;
	ft_print_array_i(a.arr, a.size);
	printf("start = %d end = %d\n", start, end);
	while (!(a.arr[i] >= start && a.arr[i] <= end) && i < (int)a.size)
		i++;
	if (i < (int)a.size)
		first = i;
	i = a.size - 1;
	while ((!(a.arr[i] >= start && a.arr[i] <= end) && i > 0))
		i--;
	if (i > 0)
		second = i;
	printf("first = %d second = %d\n", first, second);
	if (first < second)
		return (first);
	return (second);
}

int				chunks(t_main *m, t_stack *a, t_stack *b, t_list **h)
{
	int			i;
	int			pos;
	int			num;
	t_stack		*c;

	i = 0;
	pos = 0;
	c = create_chunks(*m, *a);
	printf("size = %zu\n", c->size);
	while ((c->size)-- > 1)
	{
		while ((pos = find_to_push(*a, c->arr[i], c->arr[i + 1])) >= 0)
		{
			printf("topush = %d\n\n", a->arr[i]);
			num = a->arr[pos];
			if (i > (int)(a->size / 2))
			{
				while (a->arr[0] != num)
					add_elem_to_list(h, rev_rotate(a, A));
			}
			else
				while (a->arr[0] != num)
					add_elem_to_list(h, rotate(a, A));
			push_to_b(a, b, h);
		}
		i++;
	}
	//free_chunk
	max_to_the_top(b, h);
	while (b->size > 0)
		add_elem_to_list(h, push(a, b, B));
	return (1);
}