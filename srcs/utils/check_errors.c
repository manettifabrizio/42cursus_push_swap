/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:05:38 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/19 10:10:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				error(t_stack *s)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	free(s->a);
	if (s->b)
		free(s->b);
	return (0);
}

int				check_stack(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!(ft_isdigit(s[i]) || ft_isspace(s[i]) ||
			s[i] == '+' || s[i] == '-'))
			return (0);
	return (1);
}

int				check_dup(int *a, size_t size)
{
	int		i;
	int		x;

	i = -1;
	while (++i < (int)size)
	{
		x = -1;
		while (++x < (int)size)
			if (a[i] == a[x] && i != x)
				return (0);
	}
	return (1);
}

int				check_op(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (ft_isalpha(s[i]) == 0)
			return (0);
	return (1);
}