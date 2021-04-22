/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/22 00:32:00 by fmanetti         ###   ########.fr       */
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

	i = (av[1][0] == '-') ? 1 : 0;
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

static t_stack	*str_to_arr_i(char **av)
{
	int			i;
	t_stack		*s;
	char		**tmp;

	i = (av[1][0] == '-') ? 1 : 0;
	if (!(s = malloc(sizeof(t_stack))))
		return (NULL);
	s->size = 0;
	while (av[++i])
	{
		tmp = ft_split(av[i], ' ');
		s->size += ft_arrlen(tmp);
		ft_free_array(tmp);
	}
	if (!(s->arr = create_arr_i(av, s->size)))
		return (NULL);
	if (!(check_dup(*s)))
		return (NULL);
	return (s);
}

static int		check_options(char *s, t_opt *opt)
{
	int		i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'v')
			opt->v = 1;
		else if (s[i] == 'c')
			opt->c = 1;
		else
			return (0);
	}
	if (i == 1)
		return (0);
	else
		return (1);
}

int				create_stacks(char **av, t_main *m)
{
	m->a = NULL;
	m->b = NULL;
	if (!(m->opt = malloc(sizeof(t_opt))))
		return (0);
	m->opt->v = 0;
	m->opt->c = 0;
	if (av[1][0] == '-')
		if (!(check_options(av[1], m->opt)))
			return (0);
	if (!(m->a = str_to_arr_i(av)))
		return (0);
	if (!(m->b = malloc(sizeof(t_stack))))
		return (0);
	m->b->size = 0;
	m->size_max = m->a->size;
	if (!(m->b->arr = malloc((m->size_max + 1) * sizeof(int))))
		return (0);
	return (1);
}
