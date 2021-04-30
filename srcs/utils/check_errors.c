/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:05:38 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 14:28:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_all(t_main *m)
{
	if (m->a)
		free(m->a->arr);
	if (m->b)
		free(m->b->arr);
	if (m->opt)
		free(m->opt);
}

int				error(t_main *m)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	free_all(m);
	return (0);
}

int				check_stack(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!(ft_isdigit(s[i]) || ft_isspace(s[i]) ||
			((s[i] == '+' || s[i] == '-') && ft_isdigit(s[i + 1]))))
			return (0);
	return (1);
}

int				check_dup(t_stack s)
{
	int		i;
	int		x;

	i = -1;
	while (++i < (int)s.size)
	{
		x = -1;
		while (++x < (int)s.size)
			if (s.arr[i] == s.arr[x] && i != x)
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