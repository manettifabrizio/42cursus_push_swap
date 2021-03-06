/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:09:17 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:34:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		only_rotation(t_stack *a)
{
	if (is_already_sort(*a))
	{
		while (!(stack_is_sort(*a)))
			if (min_pos(*a) <= ((int)a->size / 2))
				printf("%s\n", rotate(a, A));
			else
				printf("%s\n", rev_rotate(a, A));
		return (1);
	}
	return (0);
}

static int		choose_method(t_main *m, t_list **h)
{
	if (stack_is_sort(*(m->a)) || only_rotation(m->a))
		return (1);
	else
	{
		if (m->size_max == 2)
			printf("%s\n", ROTATE_A);
		else if (m->size_max >= 3 && m->size_max <= 5)
			return (three_to_five(m));
		else if (m->size_max >= 6)
			chunks(m, m->a, m->b, h);
	}
	return (1);
}

static void		print_and_free_list(t_list **head)
{
	t_list	*l;
	t_list	*tmp;

	l = *head;
	while (l)
	{
		tmp = l;
		printf("%s\n", (char*)(l->content));
		l = l->next;
		free(tmp);
	}
}

int				main(int ac, char **av)
{
	t_main	m;
	t_list	*head;

	if (ac < 2)
		return (0);
	head = NULL;
	m.opt = NULL;
	m.is_opt = 0;
	if (!(create_stacks(&m, av)) || !(choose_method(&m, &head)))
		return (error(&m));
	optimize_rotation(&head);
	print_and_free_list(&head);
	free_all(&m);
}
