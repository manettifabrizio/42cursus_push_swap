/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/28 14:20:04 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			add_elem_to_list(t_list **h, char *s)
{
	t_list	*new;

	// printf("[ %s ]\n", s);
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

static int		choose_rotation(int a, t_stack b)
{
	int			x;
	int			y;
	t_stack		tmp;

	x = 0;
	y = 0;
	tmp.arr = malloc(b.size * sizeof(int));
	tmp.size = b.size;
	while (x < (int)b.size)
	{
		tmp.arr[x] = b.arr[x];
		x++;
	}
	x = 0;
	while (!(a > tmp.arr[0] && a < tmp.arr[tmp.size - 1])
			&& !((a < find_min(tmp) || a > find_max(tmp)) 
			&& tmp.arr[0] == find_max(tmp)))
	{
		rotate(&tmp, NO_PRINT);
		x++;
	}
	y = 0;
	while (y < (int)b.size)
	{
		tmp.arr[y] = b.arr[y];
		y++;
	}
	y = 0;
	while (!(a > tmp.arr[0] && a < tmp.arr[tmp.size - 1])
			&& !((a < find_min(tmp) || a > find_max(tmp)) 
			&& tmp.arr[0] == find_max(tmp)))
	{
		rev_rotate(&tmp, NO_PRINT);
		y++;
	}
	// printf("x = %d y = %d\n", x, y);
	if (x < y)
		return (1);
	return (0);
}

static void		push_to_b(t_stack *a, t_stack *b, t_list **h)
{
	int		size;

	size = b->size;
	// ft_print_array_i(a->arr, a->size);
	// ft_putstr("------------\n");
	// ft_print_array_i(b->arr, b->size);
	while (b->size != (size_t)(size + 1))
	{
		if (b->size == 0)
			add_elem_to_list(h, push(b, a, B));
		else if ((a->arr[0] < find_min(*b) && b->arr[0] == find_max(*b)) ||
				(a->arr[0] > find_max(*b) && b->arr[0] == find_max(*b)) ||
				(a->arr[0] > b->arr[0] && a->arr[0] < b->arr[b->size - 1]))
			add_elem_to_list(h, push(b, a, B));
		else if (choose_rotation(a->arr[0], *b))
			add_elem_to_list(h, rotate(b, B));
		else
			add_elem_to_list(h, rev_rotate(b, B));
		// ft_print_array_i(a->arr, a->size);
		// ft_putstr("------------\n");
		// ft_print_array_i(b->arr, b->size);
	}
}

static int		find_to_push(t_stack a, int start, int end)
{
	int		i;
	int		first;
	int		second;

	i = 0;
	if (!a.size)
		return (-1);
	first = -1;
	second = -1;
	// ft_print_array_i(a.arr, a.size);
	// printf("start = %d end = %d\n", start, end);
	while (!(a.arr[i] >= start && a.arr[i] <= end) && i < (int)a.size)
		i++;
	if (i < (int)a.size)
		first = i;
	i = a.size - 1;
	while ((!(a.arr[i] >= start && a.arr[i] <= end) && i > 0))
		i--;
	if (i > 0)
		second = i;
	// printf("first = %d second = %d\n", a.arr[first], a.arr[second]);
	if (first < ((int)a.size - second) || second == -1)
		return (first);
	return (second);
}

int				chunks(t_main *m, t_stack *a, t_stack *b, t_list **h)
{
	int			i;
	int			pos;
	int			num;
	t_stack		*c;
	// FILE		*f;

	i = 0;
	pos = 0;
	// f = fopen("ciao", "w");
	c = create_chunks(*m, *a);
	// printf("size = %zu\n", c->size);
	while ((c->size)-- > 1)
	{
		while ((pos = find_to_push(*a, c->arr[i], c->arr[i + 1])) >= 0)
		{
			// printf("topush = %d i = %d\n\n", a->arr[pos], i);
			num = a->arr[pos];
			if (pos > ((int)a->size / 2))
			{
				while (a->arr[0] != num)
					add_elem_to_list(h, rev_rotate(a, A));
			}
			else
				while (a->arr[0] != num)
					add_elem_to_list(h, rotate(a, A));
			push_to_b(a, b, h);
			// for(int i = 0; i < (int)a->size; i++)
			// 	fprintf(f, "%d ", a->arr[i]);
			// fprintf(f, "\n********************************************\n");
			// print_stacks(*m, *a, *b);
		}
		i++;
	}
	// fclose(f);
	//free_chunk
	max_to_the_top(b, h);
	while (b->size > 0)
	{
		// print_stacks(*m, *a, *b);
		add_elem_to_list(h, push(a, b, A));
	}
	return (1);
}