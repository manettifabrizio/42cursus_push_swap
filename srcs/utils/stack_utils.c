/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 16:48:52 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stacks(t_stack s)
{
	int		i;

	i = -1;
	printf("a	b\n");
	printf("-	-\n");
	while (++i < (int)s.size_max)
	{
		if (i < (int)s.size_a)
			printf("%d", s.a[i]);
		else
			printf(" ");
		printf("\t");
		if (i < (int)s.size_b)
			printf("%d", s.b[i]);
		printf("\n");
	}
	printf("-	-\n\n");
}

void			stack_scale(int *a, size_t *size)
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

void			stack_del_one(int *a, size_t *size)
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

int				stack_is_sort(int *a, size_t size)
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