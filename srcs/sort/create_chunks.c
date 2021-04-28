/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:13:30 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/28 15:38:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*five(t_stack a)
{
	int			med;
	t_stack		*c;
	
	med = find_median(a);
	if (!(c = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(c->arr = malloc(6 * sizeof(int))))
		return (NULL);
	c->size = 6;
	c->arr[0] = find_min(a);
	c->arr[1] = (find_min(a) + (med - 10)) / 2;
	c->arr[2] = med - 10;
	c->arr[3] = med + 10;
	c->arr[4] = (find_max(a) + (med + 10)) / 2;
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
	int		n;

	if (m.size_max >= 6 && m.size_max <= 50)
		return (two(a));
	else if (m.size_max >= 51 && m.size_max <= 100)
		return (five(a));
	else if (m.size_max >= 101 && m.size_max <= 500)
		n = 11;
	return (NULL);
}