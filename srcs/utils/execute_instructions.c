/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:27:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/05 16:52:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		select_rotate(t_stack *s, char *inst)
{
	if (ft_strcmp(inst, "ra") == 0)
		return (rotate(s->a, s->size_a));
	if (ft_strcmp(inst, "rb") == 0)
		return (rotate(s->b, s->size_b));
	if (ft_strcmp(inst, "rr") == 0)
	{
		rotate(s->a, s->size_a);
		rotate(s->b, s->size_b);
		return (1);
	}
	if (ft_strcmp(inst, "rra") == 0)
		return (rev_rotate(s->a, s->size_a));
	if (ft_strcmp(inst, "rrb") == 0)
		return (rev_rotate(s->b, s->size_b));
	if (ft_strcmp(inst, "rrr") == 0)
	{
		rev_rotate(s->a, s->size_a);
		rev_rotate(s->b, s->size_b);
		return (1);
	}
	return (0);
}

static int		select_push(t_stack *s, char *inst)
{
	if (ft_strcmp(inst, "pa") == 0)
		return (push(s->a, s->b, &(s->size_a), &(s->size_b)));
	if (ft_strcmp(inst, "pb") == 0)
		return (push(s->b, s->a, &(s->size_b), &(s->size_a)));
	return (0);
}

static int		select_swap(t_stack *s, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0)
		return (swap(s->a, s->size_a));
	if (ft_strcmp(inst, "sb") == 0)
		return (swap(s->b, s->size_b));
	if (ft_strcmp(inst, "ss") == 0)
	{
		swap(s->a, s->size_a);
		swap(s->b, s->size_b);
		return (1);
	}
	return (0);
}

static int		select_instruction(t_stack *s, char *inst)
{
	if (inst[0] == 's')
		return (select_swap(s, inst));
	if (inst[0] == 'p')
		return (select_push(s, inst));
	if (inst[0] == 'r')
		return (select_rotate(s, inst));
	return (0);
}

static void		print(t_stack s)
{
	int		i;

	i = -1;
	ft_putstr("a = ( ");
	while (++i < (int)s.size_a)
	{
		ft_putnbr(s.a[i]);
		ft_putchar(' ');
	}
	ft_putstr(")\n");
	i = -1;
	ft_putstr("b = ( ");
	while (++i < (int)s.size_b)
	{
		ft_putnbr(s.b[i]);
		ft_putchar(' ');
	}
	ft_putstr(")\n");
}

int		execute_instructions(t_stack *s, char *inst)
{
	if (!(check_inst(inst)))
		return (0);
	if (!(select_instruction(s, inst)))
	{
		free(inst);
		return (0);
	}
	free(inst);
	print(*s);
	return (1);
}