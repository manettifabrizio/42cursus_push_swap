/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:30:01 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 17:46:45 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				swap_a(int *a, size_t size)
{
	printf("%s\n", SWAP_A);
	if (size > 1)
		ft_swap(&(a[0]), &(a[1]));
	return (1);
}

int				swap_b(int *a, size_t size)
{
	printf("%s\n", SWAP_B);
	if (size > 1)
		ft_swap(&(a[0]), &(a[1]));
	return (1);
}

int				swap_ab(int *a, int *b, size_t size_a, size_t size_b)
{
	printf("%s\n", SWAP_AB);
	if (size_a > 1)
		ft_swap(&(a[0]), &(a[1]));
	if (size_b > 1)
		ft_swap(&(b[0]), &(b[1]));
	return (1);
}