/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:13:30 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:23:23 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create(t_stack a, int chunks_nbr)
{
	int			x;
	int			*tmp;
	t_stack		*c;
	int			i;
	int			chunks_size;

	tmp = ft_sort_array_i(ft_arrdup_i(a.arr, a.size), a.size);
	if (!(c = malloc(sizeof(t_stack))))
		return (NULL);
	c->size = chunks_nbr + 1;
	if (!(c->arr = malloc((c->size) * sizeof(int))))
		return (NULL);
	chunks_size = a.size / chunks_nbr;
	c->arr[0] = find_min(a);
	x = 0;
	i = chunks_size - 1;
	while (++x < chunks_nbr)
	{
		c->arr[x] = tmp[i];
		i += chunks_size;
	}
	c->arr[x] = find_max(a);
	free(tmp);
	return (c);
}

t_stack			*create_chunks(t_main m, t_stack a)
{
	if (m.size_max >= 6 && m.size_max <= 50)
		return (create(a, 2));
	else if (m.size_max >= 51 && m.size_max <= 300)
		return (create(a, 5));
	else if (m.size_max >= 301 && m.size_max <= 500)
		return (create(a, 13));
	else if (m.size_max > 500)
		return (create(a, 20));
	return (NULL);
}
