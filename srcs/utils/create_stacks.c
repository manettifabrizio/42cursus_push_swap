/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 10:43:04 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*create_arr_i(char **av, size_t size)
{
	int		i;
	int		x;
	int		y;
	int		*a;
	char	**tmp;

	i = 0;
	y = -1;
	if (!(a = malloc((size) * sizeof(int))))
		return (NULL);
	while (av[++i])
	{
		if (!(check_stack(av[i])))
			return (NULL);
		x = -1;
		tmp = ft_split(av[i], ' ');
		while (tmp[++x])
			a[++y] = ft_atoi(tmp[x]);
		ft_free_array(tmp);
	}
	return (a);
}

static int		*str_to_arr_i(char **av, size_t *size)
{
	int		i;
	int		*a;
	char	**tmp;

	i = 0;
	(*size) = 0;
	while (av[++i])
	{
		tmp = ft_split(av[i], ' ');
		(*size) += ft_arrlen(tmp);
		ft_free_array(tmp);
	}
	a = create_arr_i(av, *size);
	if (!(check_dup(a, *size)))
		return (NULL);
	return (a);
}

int				create_stacks(char **av, t_stack *s)
{
	if (!(s->a = str_to_arr_i(av, &(s->size_a))))
		return (0);
	s->size_b = 0;
	s->size_max = s->size_a;
	if (!(s->b = malloc((s->size_max + 1) * sizeof(int))))
		return (0);
	return (1);
}
