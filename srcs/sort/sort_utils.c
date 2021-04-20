/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:04:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 12:27:04 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_min(int *a, size_t size)
{
	int		i;
	int		min;

	i = -1;
	min = a[0];
	while (++i < (int)size)
		if (a[i] < min)
			min = a[i];
	return (min);
}

int				find_max(int *a, size_t size)
{
	int		i;
	int		max;

	i = -1;
	max = a[0];
	while (++i < (int)size)
		if (a[i] > max)
			max = a[i];
	return (max);
}

int				min_pos(int *a, int size)
{
	int		x;
	int		min;

	x = 0;
	min = find_min(a, size);
	while (a[x] != min && x < size)
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

int				is_already_sort(int *a, size_t size)
{
	int		x;
	int		y;
	int		min;
	int		*tmp;

	if (!(tmp = malloc(size * sizeof(int))))
		return (0);
	min = find_min(a, size);
	x = 0;
	while (a[x] != min)
		x++;
	x = choose_x(x, size);
	y = 1;
	tmp[0] = min;
	while (a[x] != min)
	{
		tmp[y++] = a[x];
		x = choose_x(x, size);
	}
	x = stack_is_sort(tmp, size);
	free(tmp);
	return (x);
}
