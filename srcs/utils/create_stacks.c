/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/25 18:20:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		create_arr_i(t_stack *a, char **av, int is_opt)
{
	int		i;
	int		x;
	int		y;
	char	**tmp;

	if (!(a->arr = malloc((a->size) * sizeof(int))))
		return (0);
	i = (is_opt == 1) ? 1 : 0;
	y = -1;
	while (av[++i])
	{
		if (!(tmp = check_stack(av[i])))
			return (0);
		x = -1;
		while (tmp[++x])
			a->arr[++y] = ft_atoi(tmp[x]);
		ft_free_array(tmp);
	}
	return (1);
}

static int		str_is_empty(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!(ft_isspace(s[i])))
			return (0);
	if (i == 0 || i == (int)ft_strlen(s))
		return (1);
	return (0);
}

static int		str_to_arr_i(t_main *m, char **av, int is_opt)
{
	int			i;
	char		**tmp;

	i = (is_opt == 1) ? 2 : 1;
	if (str_is_empty(av[i]))
		return (0);
	if (!(m->a = malloc(sizeof(t_stack))))
		return (0);
	m->a->size = 0;
	i -= 1;
	while (av[++i])
	{

		tmp = ft_split(av[i], ' ');
		m->a->size += ft_arrlen(tmp);
		ft_free_array(tmp);
	}
	if (!(create_arr_i(m->a, av, is_opt)))
		return (0);
	if (!(check_dup(*(m->a))))
		return (0);
	return (1);
}

int				create_stacks(t_main *m, char **av)
{
	m->a = NULL;
	m->b = NULL;
	if (!(str_to_arr_i(m, av, m->is_opt)))
		return (0);
	if (!(m->b = malloc(sizeof(t_stack))))
		return (0);
	m->b->size = 0;
	m->size_max = m->a->size;
	if (!(m->b->arr = malloc((m->size_max) * sizeof(int))))
		return (0);
	return (1);
}
