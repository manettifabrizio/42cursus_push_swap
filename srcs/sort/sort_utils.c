/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:04:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/21 23:37:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_min(t_stack s)
{
	int		i;
	int		min;

	i = -1;
	min = s.arr[0];
	while (++i < (int)s.size)
		if (s.arr[i] < min)
			min = s.arr[i];
	return (min);
}

int				find_max(t_stack s)
{
	int		i;
	int		max;

	i = -1;
	max = s.arr[0];
	while (++i < (int)s.size)
		if (s.arr[i] > max)
			max = s.arr[i];
	return (max);
}

int				min_pos(t_stack s)
{
	int		x;
	int		min;

	x = 0;
	min = find_min(s);
	while (s.arr[x] != min && x < (int)s.size)
		x++;
	return (x);
}

static int		choose_x(int x, size_t size)
{
	if (x == (int)size - 1)
		return (0);
	else
		return (x + 1);
}

int				is_already_sort(t_stack s)
{
	int			x;
	int			y;
	int			min;
	t_stack		tmp;

	tmp.size = s.size;
	if (!(tmp.arr = malloc(s.size * sizeof(int))))
		return (0);
	min = find_min(s);
	x = 0;
	while (s.arr[x] != min)
		x++;
	x = choose_x(x, s.size);
	y = 1;
	tmp.arr[0] = min;
	while (s.arr[x] != min)
	{
		tmp.arr[y++] = s.arr[x];
		x = choose_x(x, s.size);
	}
	x = stack_is_sort(tmp);
	free(tmp.arr);
	return (x);
}
