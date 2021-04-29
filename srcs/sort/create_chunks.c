/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:13:30 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/29 18:15:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				*ft_arrdup_i(int *a, size_t size)
{
	int		i;
	int		*b;

	i = -1;
	if (!(b = malloc(size * sizeof(int))))
		return (NULL);
	while (++i < (int)size)
		b[i] = a[i];
	return (b);
}

static t_stack	*thirteen(t_stack a)
{
	int			*med;
	t_stack		*c;
	
	med = ft_sort_array_i(ft_arrdup_i(a.arr, a.size), a.size);
	if (!(c = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(c->arr = malloc(14 * sizeof(int))))
		return (NULL);
	c->size = 6;
	c->arr[0] = find_min(a);
	c->arr[1] = med[37];
	c->arr[2] = med[75];
	c->arr[3] = med[113];
	c->arr[4] = med[151];
	c->arr[5] = med[189];
	c->arr[6] = med[227];
	c->arr[7] = med[265];
	c->arr[8] = med[303];
	c->arr[9] = med[341];
	c->arr[10] = med[379];
	c->arr[11] = med[418];
	c->arr[12] = med[456];
	c->arr[13] = find_max(a);
	return (c);
}

static t_stack	*five(t_stack a)
{
	int			*med;
	t_stack		*c;
	
	med = ft_sort_array_i(ft_arrdup_i(a.arr, a.size), a.size);
	if (!(c = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(c->arr = malloc(6 * sizeof(int))))
		return (NULL);
	c->size = 6;
	c->arr[0] = find_min(a);
	c->arr[1] = med[19];
	c->arr[2] = med[39];
	c->arr[3] = med[59];
	c->arr[4] = med[79];
	c->arr[5] = find_max(a);
	return (c);
}

static t_stack	*two(t_stack a)
{
	int			med;
	t_stack		*c;

	med = find_median(a);
	if (!(c = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(c->arr = malloc(3 * sizeof(int))))
		return (NULL);
	c->size = 3;
	c->arr[0] = find_min(a);
	c->arr[1] = med;
	c->arr[2] = find_max(a);
	// ft_print_array_i(c->arr, c->size);
	return (c);
}

t_stack			*create_chunks(t_main m, t_stack a)
{
	if (m.size_max >= 6 && m.size_max <= 50)
		return (two(a));
	else if (m.size_max >= 51 && m.size_max <= 100)
		return (five(a));
	else if (m.size_max >= 101 && m.size_max <= 500)
		return (thirteen(a));
	return (NULL);
}