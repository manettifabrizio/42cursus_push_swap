/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:09:17 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/26 16:55:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_method(t_main *m, t_list **h)
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
		else if (m->size_max >= 3 && m->size_max <= 5)
			return (three_to_five(m));
		else if (m->size_max >= 6 && m->size_max < 500)
		{
			chunks(m, m->a, m->b, h);
			t_list		*l;
			l = *h;
			while (l)
			{
				printf("%s\n", l->content);
				l = l->next;
			}
		}
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
	if (!(create_stacks(av, &m)) || !(choose_method(&m, &head)))
		return (error(&m));
	free(m.a);
	free(m.b);
}