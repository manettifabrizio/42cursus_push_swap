/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:57:43 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 11:25:24 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_sort_array_i(int *a, size_t size)
{
	int		x;

	x = 0;
	while ((x + 1) < (int)size)
		if (a[x] > a[x + 1])
		{
			ft_swap(&(a[x]), &(a[x + 1]));
			x = 0;
		}
		else
			x++;
	return (a);
}

char		**ft_sort_array_c(char **a)
{
	int		x;

	x = 0;
	while (a[x + 1])
		if (ft_strcmp(a[x], a[x + 1]) > 0)
		{
			ft_swap_c(&(a[x]), &(a[x + 1]));
			x = 0;
		}
		else
			x++;
	return (a);
}
