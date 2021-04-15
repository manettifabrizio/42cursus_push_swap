/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:04:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/16 01:27:54 by fmanetti         ###   ########.fr       */
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