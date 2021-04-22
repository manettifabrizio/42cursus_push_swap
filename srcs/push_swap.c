/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:09:17 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/22 13:56:14 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_method(t_main *m, t_list *h)
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
		else if (m->size_max > 5 && m->size_max < 50)
			return (six_to_fifty(m, m->a, m->b, h));
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_main	m;
	t_list	*head;

	if (ac < 2)
		return (0);
	if (!(head = ft_lstnew(NULL)))
		return (0);
	if (!(create_stacks(av, &m)) || !(choose_method(&m, head)))
		return (error(&m));
	free(m.a);
	free(m.b);
}