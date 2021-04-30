/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 17:43:30 by fmanetti         ###   ########.fr       */
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
	int		size;

	size = b->size;
	while (b->size != (size_t)(size + 1))
	{
		if (b->size == 0)
			add_elem_to_list(h, push(b, a, B));
		else if ((a->arr[0] < find_min(*b) && b->arr[0] == find_max(*b)) ||
				(a->arr[0] > find_max(*b) && b->arr[0] == find_max(*b)) ||
				(a->arr[0] > b->arr[0] && a->arr[0] < b->arr[b->size - 1]))
			add_elem_to_list(h, push(b, a, B));
		else if (choose_rotation_a_b(a->arr[0], *b))
			add_elem_to_list(h, rotate(b, B));
		else
			add_elem_to_list(h, rev_rotate(b, B));
	}
}

static int		find_to_push(t_stack a, int start, int end)
{
	int		i;
	int		first;

	i = 0;
	if (!a.size)
		return (-1);
	first = -1;
	while (!(a.arr[i] >= start && a.arr[i] <= end) && i < (int)a.size)
		i++;
	if (i < (int)a.size)
		first = i;
	return (first);
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
	while ((c->size)-- > 1)
	{
		while ((pos = find_to_push(*a, c->arr[i], c->arr[i + 1])) >= 0)
		{
			num = a->arr[pos];
				while (a->arr[0] != num)
					add_elem_to_list(h, rotate(a, A));
			push_to_b(a, b, h);
		}
		i++;
	}
	max_to_the_top(b, h);
	while (b->size > 0)
		add_elem_to_list(h, push(a, b, A));
	return (1);
}