/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/05 17:19:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_scale(int *a, size_t *size)
{
	int		i;

	i = (int)(*size);
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	(*size)++;
}

void	stack_del_one(int *a, size_t *size)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)(*size))
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size)--;
}

int		stack_is_sort(int *a, size_t size)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)size)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}