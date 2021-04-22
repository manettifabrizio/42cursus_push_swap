/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_to_fifty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:23:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/22 16:23:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				six_to_fifty(t_main *m, t_stack *a, t_stack *b, t_list *h)
{
	int		min;
	int		max;

	(void)m;
	(void)h;
	min = find_min(*a);
	max = find_max(*a);
	printf("%s\n", push(b, a, B));
	printf("%s\n", push(b, a, B));
	while (a->size > 0)
	{
		if ((a->arr[0] == max && b->arr[0] == find_max(*b)) ||
			(a->arr[0] == min && b->arr[0] == find_max(*b)) ||
			(a->arr[0] > find_min(*b) && b->arr[0] != min) ||
			(a->arr[0] < find_max(*b) && b->arr[0] != max) ||
			(a->arr[0] > b->arr[0] && a->arr[0] < b->arr[b->size - 1]))
			printf("%s\n", push(b, a, B));
		else if (a->arr[0] < b->arr[0] && a->arr[0] > b->arr[1])
			printf("%s\n", rotate(b, B));
		else
			printf("%s\n", rev_rotate(b, B));
	}
	while (!(stack_is_sort(*b)))
		if (min_pos(*b) <= 2)
			printf("%s\n", rotate(b, B));
		else
			printf("%s\n", rev_rotate(b, B));
	while (b->size > 0)
		printf("%s\n", push(a, b, A));
	return (1);
}