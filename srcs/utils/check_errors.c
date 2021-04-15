/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:05:38 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/15 20:59:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error(t_stack *s)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	free(s->a);
	free(s->b);
	return (0);
}

int		check_stack(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (0);
	return (1);
}

int		check_dup(char **a)
{
	int		i;
	int		x;

	i = 0;
	while (a[++i])
	{
		x = 0;
		while (a[++x])
			if (ft_strcmp(a[i], a[x]) == 0 && i != x)
				return (0);
	}
	return (1);
}

int		check_op(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (ft_isalpha(s[i]) == 0)
			return (0);
	return (1);
}