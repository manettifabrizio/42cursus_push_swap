/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:42:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 18:14:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				rotate_a(int *a, size_t size)
{
	int		i;
	int		tmp;


	printf("%s\n", ROTATE_A);
	if (size > 1)
	{
		tmp = a[0];
		i = -1;
		while (++i < (int)(size - 1))
			a[i] = a[i + 1];
		a[size - 1] = tmp;
	}
	return (1);
}

int				rotate_b(int *a, size_t size)
{
	int		i;
	int		tmp;

	printf("%s\n", ROTATE_B);
	if (size > 1)
	{
		tmp = a[0];
		i = -1;
		while (++i < (int)(size - 1))
			a[i] = a[i + 1];
		a[size - 1] = tmp;
	}
	return (1);
}

int				rotate_ab(int *a, int *b, size_t size_a, size_t size_b)
{
	int		i;
	int		tmp;

	printf("%s\n", ROTATE_AB);
	if (size_a > 1)
	{
		tmp = a[0];
		i = -1;
		while (++i < (int)(size_a - 1))
			a[i] = a[i + 1];
		a[size_a - 1] = tmp;
	}
	if (size_b > 1)
	{
		tmp = b[0];
		i = -1;
		while (++i < (int)(size_b - 1))
			b[i] = b[i + 1];
		b[size_b - 1] = tmp;
	}
	return (1);
}