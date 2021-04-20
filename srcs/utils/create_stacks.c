/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/20 17:18:03 by fmanetti         ###   ########.fr       */
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

static int		check_options(char *s, t_opt *opt)
{
	int		i;

	i = 0;
	opt->v = 0;
	opt->c = 0;
	while (s[++i])
	{
		if (s[i] == 'v')
			opt->v = 1;
		else if (s[i] == 'c')
			opt->c = 1;
		else
			return (0);
	}
}

int				create_stacks(char **av, t_main *m)
{
	if (av[1][0] == '-')
		if (!check_options(av[1][0], m->opt))
			return (0);
	if (!(m->a->arr = str_to_arr_i(av, &(m->a->size))))
		return (0);
	m->b->size = 0;
	m->size_max = m->a->size;
	if (!(m->b->arr = malloc((m->size_max + 1) * sizeof(int))))
		return (0);
	return (1);
}
