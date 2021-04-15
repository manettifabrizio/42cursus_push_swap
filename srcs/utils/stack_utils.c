/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/16 00:40:37 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stacks(t_stack s)
{
	int		i;

	i = -1;
	ft_putstr("a	b\n");
	ft_putstr("-	-\n");
	while (++i < (int)s.size_max)
	{
		if (i < (int)s.size_a)
			ft_putnbr(s.a[i]);
		else
			ft_putchar(' ');
		ft_putchar('\t');
		if (i < (int)s.size_b)
			ft_putnbr(s.b[i]);
		ft_putchar('\n');
	}
	ft_putstr("-	-\n\n");
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