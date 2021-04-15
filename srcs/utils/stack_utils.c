/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 18:07:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*str_to_arr_i(char **av, int ac)
{
	int		i;
	int		*a;
	int		size;

	size = ac - 1;
	if (!(a = malloc(size * sizeof(int))))
		return (NULL);
	i = -1;
	while (av[++i + 1])
	{
		if (!(check_stack(av[i + 1])) || !(check_dup(av)))
			return (NULL);
		a[i] = ft_atoi(av[i + 1]);
	}
	return (a);
}

int				create_stacks(int ac, char **av, t_stack *s)
{
	if (!(s->a = str_to_arr_i(av, ac)))
		return (0);
	s->size_a = ac - 1;
	s->size_b = 0;
	s->size_max = s->size_a;
	if (!(s->b = malloc((s->size_max + 1) * sizeof(int))))
		return (0);
	return (1);
}

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