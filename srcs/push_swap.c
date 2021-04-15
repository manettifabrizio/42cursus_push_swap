/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:09:17 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 21:00:37 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_method(t_stack s)
{
	if (stack_is_sort(s.a, s.size_a))
		return (1);
	else
	{
		if (s.size_max == 2)
		{
			printf("%s\n", ROTATE_A);
			return (1);
		}
		else if (s.size_max > 2 && s.size_max < 6)
			return (three_to_five(&s));
		else if (s.size_max > 5 && s.size_max < 500)
			return (chunks());
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_stack s;

	if (ac < 2)
		return (0);
	if (!(create_stacks(ac, av, &s)) || !(choose_method(s)))
		return (error(&s));
	free(s.a);
	free(s.b);
}