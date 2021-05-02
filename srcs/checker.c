/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:20:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		debug_or_execute(t_main *m, char **a)
{
	int		i;

	i = -1;
	if (m->opt->v)
		debug_mode(m, a);
	else if (a)
		while (a[++i])
			if (!(execute(m, a[i])))
				break ;
	i = (m->opt->v || i == (int)ft_arrlen(a)) ? 1 : 0;
	ft_free_array(a);
	return (i);
}

static int		read_and_execute(t_main *m)
{
	char	*op;
	char	**a;

	if (m->size_max == 1)
		return (1);
	a = NULL;
	op = NULL;
	if (m->opt->d)
		print_stacks(*m, m->size_max, NULL);
	while (get_next_line(STDIN_FILENO, &op) > 0)
	{
		(m->ops_nbr)++;
		a = add_elem_to_arr(a, op);
		free(op);
	}
	if (op)
		free(op);
	if (a)
		if (!(debug_or_execute(m, a)))
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_main	m;

	if (ac < 2)
		return (0);
	m.ops_nbr = 0;
	m.a = NULL;
	m.b = NULL;
	m.is_opt = 0;
	if (!(options(&m, av[1])))
		return (error(&m));
	if (!(create_stacks(&m, av)) || !(read_and_execute(&m)))
		return (error(&m));
	if (stack_is_sort(*(m.a)) && m.b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	if (m.opt->o)
		printf("Total number of operations: %s%d%s\n", GREEN, m.ops_nbr,
			NO_COLOR);
	free_all(&m);
	return (0);
}
