/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:49:32 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 17:53:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				rev_rotate_a(int *a, size_t size)
{
	int		i;
	int		tmp;

	printf("%s\n", ROTATE_A);
	if (size > 1)
	{
		tmp = a[size - 1];
		i = size;
		while (--i > 0)
			a[i] = a[i - 1];
		a[0] = tmp;
	}
	return (1);
}

int				rev_rotate_b(int *a, size_t size)
{
	int		i;
	int		tmp;

	printf("%s\n", ROTATE_B);
	if (size > 1)
	{
		tmp = a[size - 1];
		i = size;
		while (--i > 0)
			a[i] = a[i - 1];
		a[0] = tmp;
	}
	return (1);
}

int				rev_rotate_ab(int *a, int *b, size_t size_a, size_t size_b)
{
	int		i;
	int		tmp;

	printf("%s\n", ROTATE_AB);
	if (size_a > 1)
	{
		tmp = a[size_a - 1];
		i = size_a;
		while (--i > 0)
			a[i] = a[i - 1];
		a[0] = tmp;
	}
	if (size_b > 1)
	{
		tmp = b[size_b - 1];
		i = size_b;
		while (--i > 0)
			b[i] = b[i - 1];
		b[0] = tmp;
	}
	return (1);
}