/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:37:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 14:39:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				push_a(int *a, int *b, size_t *size_a, size_t *size_b)
{
	printf("%s\n", PUSH_A);
	if (!(*size_b))
		return (1);
	stack_scale(a, size_a);
	a[0] = b[0];
	stack_del_one(b, size_b);
	return (1);
}

int				push_b(int *b, int *a, size_t *size_b, size_t *size_a)
{
	printf("%s\n", PUSH_B);
	if (!(*size_a))
		return (1);
	stack_scale(b, size_b);
	b[0] = a[0];
	stack_del_one(a, size_a);
	return (1);
}