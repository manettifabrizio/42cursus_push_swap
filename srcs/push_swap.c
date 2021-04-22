/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:09:17 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/21 23:32:15 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_method(t_main *m)
{
	if (stack_is_sort(*(m->a)))
		return (1);
	else
	{
		if (m->size_max == 2)
		{
			printf("%s\n", ROTATE_A);
			return (1);
		}
		else if (m->size_max > 2 && m->size_max < 6)
			return (three_to_five(m));
		else if (m->size_max > 5 && m->size_max < 500)
			return (chunks());
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_main m;

	if (ac < 2)
		return (0);
	if (!(create_stacks(av, &m)) || !(choose_method(&m)))
		return (error(&m));
	free(m.a);
	free(m.b);
}