/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/27 15:31:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		read_and_execute(t_main *m)
{
	char	*op;

	if (m->opt->v)
		print_stacks(*m, *(m->a), *(m->b));
	while (get_next_line(STDIN_FILENO, &op) > 0)
	{
		(m->ops_nbr)++;
		if (!(execute(m, op)))
			return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_main	m;

	if (ac < 2)
		return (0);
	m.ops_nbr = 0;
	if (!(create_stacks(av, &m)) || !(read_and_execute(&m)))
		return (error(&m));
	if (stack_is_sort(*(m.a)) && m.b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	// printf("Total ops : %d\n", m.ops_nbr);
	free(m.a->arr);
	free(m.b->arr);
	return (0);
}