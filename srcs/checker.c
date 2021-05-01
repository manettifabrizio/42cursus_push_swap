/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/01 19:48:35 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		read_and_execute(t_main *m)
{
	char	*op;
	char	**a;

	a = NULL;
	if (m->opt->d)
		print_stacks(*m, m->size_max, NULL);
	while (get_next_line(STDIN_FILENO, &op) > 0)
	{
		(m->ops_nbr)++;
		if (m->opt->v)
			a = add_elem_to_arr(a, op);
		else
			if (!(execute(m, op)))
				return (0);
	}
	if (m->opt->v)
		debug_mode(m, a);
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
	if (!(options(&m, av[1])))
		return (error(&m));
	if (!(create_stacks(&m, av)) || !(read_and_execute(&m)))
		return (error(&m));
	if (stack_is_sort(*(m.a)) && m.b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	if (m.opt->o)
		printf("Total number of operations: %d\n", m.ops_nbr);
	free(m.a->arr);
	free(m.b->arr);
	return (0);
}