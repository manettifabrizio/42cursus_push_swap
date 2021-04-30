/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:17:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 12:21:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				*ft_arrdup_i(int *a, size_t size)
{
	int		i;
	int		*b;

	i = -1;
	if (!(b = malloc(size * sizeof(int))))
		return (NULL);
	while (++i < (int)size)
		b[i] = a[i];
	return (b);
}