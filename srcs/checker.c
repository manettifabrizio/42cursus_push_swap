/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 17:57:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		read_and_execute(t_stack *s)
{
	char	*op;

	// print_stacks(*s);
	while (get_next_line(STDIN_FILENO, &op) > 0)
	{
		(s->ops_nbr)++;
		if (!(execute(s, op)))
			return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stack	s;

	if (ac < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	s.ops_nbr = 0;
	if (!(create_stacks(av, &s)) || !(read_and_execute(&s)))
		return (error(&s));
	if (stack_is_sort(s.a, s.size_a) && s.size_b == 0)
		printf("%s | Total operations: %zu\n", OK, s.ops_nbr);
	else
		ft_putstr(KO);
	free(s.a);
	free(s.b);
	return (0);
}