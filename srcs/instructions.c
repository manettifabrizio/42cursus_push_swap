/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:56:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/05 16:52:16 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap(int *a, size_t size)
{
	if (size < 2)
		return (1);
	ft_swap(&(a[0]), &(a[1]));
	return (1);
}

int		push(int *a1, int *a2, size_t *size_a1, size_t *size_a2)
{
	if (!(*size_a2))
		return (1);
	stack_scale(a1, size_a1);
	a1[0] = a2[0];
	stack_del_one(a2, size_a2);
	return (1);
}

int		rotate(int *a, size_t size)
{
	int		i;
	int		tmp;

	if (size < 2)
		return (1);
	tmp = a[0];
	i = -1;
	while (++i < (int)(size - 1))
		a[i] = a[i + 1];
	a[size - 1] = tmp;
	return (1);
}

int		rev_rotate(int *a, size_t size)
{
	int		i;
	int		tmp;

	printf("size = %zu\n", size);
	if (size < 2)
		return (1);
	tmp = a[size - 1];
	i = size;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = tmp;
	return (1);
}