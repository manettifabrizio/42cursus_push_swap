/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:42:08 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:13:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_atol(const char *s)
{
	int		x;
	int		c;
	long	res;
	long	sign;

	x = 0;
	c = 0;
	res = 0;
	sign = 1;
	while (s[x] == ' ' || (s[x] >= 8 && s[x] <= 13))
		x++;
	if (s[x] == '-')
		sign *= -1;
	while (s[x + c] == '+' || s[x + c] == '-')
		c++;
	while (s[x + c] >= '0' && s[x + c] <= '9')
	{
		res *= 10;
		res += (long)s[x + c] - '0';
		x++;
	}
	if (c > 1)
		return (0);
	return (res * sign);
}
