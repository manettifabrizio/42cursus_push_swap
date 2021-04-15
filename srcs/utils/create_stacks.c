/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 21:58:28 by fmanetti         ###   ########.fr       */
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