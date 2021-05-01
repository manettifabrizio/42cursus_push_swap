/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:39:07 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/01 18:58:05 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		middle_pos_b_a(int n, t_stack s)
{
	int		x;

	if (n < s.arr[0] && n > s.arr[s.size - 1])
		return (0);
	x = 0;
	while ((x + 1) < (int)s.size && !(n > s.arr[x] && n < s.arr[x + 1]))
		x++;
	return (x);
}

int				choose_rotation_b_a(int n, t_stack s)
{
	if (n < find_min(s))
	{
		if (min_pos(s) <= (int)s.size / 2)
			return (1);
	}
	else if (n > find_max(s))
	{
		if (max_pos(s) <= (int)s.size / 2)
			return (1);
	}
	else
		if (middle_pos_b_a(n, s) < (int)s.size / 2)
			return (1);
	return (0);
}

static int		middle_pos_a_b(int n, t_stack s)
{
	int		x;

	if (n > s.arr[0] && n < s.arr[s.size - 1])
		return (0);
	x = 0;
	while ((x + 1) < (int)s.size && !(n < s.arr[x] && n > s.arr[x + 1]))
		x++;
	return (x);
}

int				choose_rotation_a_b(int n, t_stack s)
{
	if (n < find_min(s))
	{
		if (min_pos(s) <= (int)s.size / 2)
			return (1);
	}
	else if (n > find_max(s))
	{
		if (max_pos(s) <= (int)s.size / 2)
			return (1);
	}
	else
		if (middle_pos_a_b(n, s) < (int)s.size / 2)
			return (1);
	return (0);
}