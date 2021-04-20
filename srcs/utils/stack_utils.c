/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 17:43:44 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stacks(t_main m, t_stack a, t_stack b)
{
	int		i;

	i = -1;
	printf("a	b\n");
	printf("-	-\n");
	while (++i < (int)m.size_max)
	{
		if (i < (int)a.size)
			printf("%d", a.arr[i]);
		else
			printf(" ");
		printf("\t");
		if (i < (int)b.size)
			printf("%d", b.arr[i]);
		printf("\n");
	}
	printf("-	-\n\n");
}

void			stack_scale(t_stack *s)
{
	int		i;

	i = (int)(s->size);
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	(s->size)++;
}

void			stack_del_one(t_stack *s)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)(s->size))
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	(s->size)--;
}

int				stack_is_sort(t_stack *s)
{
	int		i;

	i = 0;
	while ((i + 1) < (int)s->size)
	{
		if (s->arr[i] > s->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}