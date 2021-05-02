/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 02:00:55 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:33:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		rev_ops(t_main *m, char *op, int ret)
{
	if (ft_strcmp(op, SWAP_A) == 0)
		swap(m->a, NO_PRINT);
	else if (ft_strcmp(op, PUSH_A) == 0)
		push(m->b, m->a, NO_PRINT);
	else if (ft_strcmp(op, PUSH_B) == 0)
		push(m->a, m->b, NO_PRINT);
	else if (ft_strcmp(op, ROTATE_A) == 0)
		rev_rotate(m->a, NO_PRINT);
	else if (ft_strcmp(op, ROTATE_B) == 0)
		rev_rotate(m->b, NO_PRINT);
	else if (ft_strcmp(op, ROTATE_AB) == 0)
	{
		rev_rotate(m->a, NO_PRINT);
		rev_rotate(m->b, NO_PRINT);
	}
	else if (ft_strcmp(op, REV_ROTATE_A) == 0)
		rotate(m->a, NO_PRINT);
	else if (ft_strcmp(op, REV_ROTATE_B) == 0)
		rotate(m->b, NO_PRINT);
	else if (ft_strcmp(op, REV_ROTATE_AB) == 0)
	{
		rotate(m->a, NO_PRINT);
		rotate(m->b, NO_PRINT);
	}
	return (ret);
}

static int		reading(t_main *m, char **a, int i)
{
	char		buf;

	buf = 0;
	read(STDOUT_FILENO, &buf, 1);
	if (buf == ESCAPE)
	{
		read(STDOUT_FILENO, &buf, 1);
		if (buf == '[')
		{
			read(STDOUT_FILENO, &buf, 1);
			if (buf == ARR_LEFT)
				if (i > -1)
					return (rev_ops(m, a[i], i - 1));
			if (buf == ARR_RIGHT)
				if (i < (int)ft_arrlen(a) - 1)
					return (i + 1);
		}
	}
	if (buf == 'q')
		return (-2);
	return (i);
}

int				debug_mode(t_main *m, char **a)
{
	int				i;
	int				tmp;
	struct termios	base_term;

	i = -1;
	tmp = i;
	tcgetattr(STDERR_FILENO, &base_term);
	set_term_noncano();
	print_stacks(*m, m->size_max, NULL);
	while ((i = reading(m, a, i)) != -2)
	{
		if (i > tmp && i < (int)ft_arrlen(a))
			execute(m, a[i]);
		else if (i < tmp)
			print_stacks(*m, m->size_max, a[i + 1]);
		tmp = i;
	}
	set_term_cano(&base_term);
	return (1);
}
