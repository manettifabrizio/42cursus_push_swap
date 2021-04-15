/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:07:08 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 11:25:03 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_i(int *a, size_t size)
{
	int		x;

	x = 0;
	while (x < (int)size)
	{
		ft_putstr("a");
		ft_putchar('[');
		ft_putnbr(x);
		ft_putchar(']');
		ft_putstr(" = |");
		ft_putnbr(a[x++]);
		ft_putstr("|\n");
	}
}

void	ft_print_array_c(char **a, char *name)
{
	int		x;

	x = 0;
	while (a[x] != NULL)
	{
		ft_putstr(name);
		ft_putchar('[');
		ft_putnbr(x);
		ft_putchar(']');
		ft_putstr(" = |");
		ft_putstr(a[x++]);
		ft_putstr("|\n");
	}
}
