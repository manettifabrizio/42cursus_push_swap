/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:48:50 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/01 21:05:11 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		colors_b(char *op, t_stack s, int i)
{
	if ((ft_strcmp(op, PUSH_B) == 0 && i == 0) ||
		((ft_strcmp(op, ROTATE_B) == 0 || ft_strcmp(op, ROTATE_AB) == 0 ||
		ft_strcmp(op, REV_ROTATE_B) == 0 || ft_strcmp(op, REV_ROTATE_AB) == 0)
		&& (i == 0 || i == (int)s.size - 1)))
		printf("%s%d%s", GREEN, s.arr[i], NO_COLOR);
	else
		printf("%d", s.arr[i]);
}

static void     colors_a(char *op, t_stack s, int i)
{
	if ((ft_strcmp(op, SWAP_A) == 0 && i >= 0 && i <= 1) ||
		(ft_strcmp(op, PUSH_A) == 0 && i == 0) ||
		((ft_strcmp(op, ROTATE_A) == 0 || ft_strcmp(op, ROTATE_AB) == 0 ||
		ft_strcmp(op, REV_ROTATE_A) == 0 || ft_strcmp(op, REV_ROTATE_AB) == 0)
		&& (i == 0 || i == (int)s.size - 1)))
		printf("%s%d%s", GREEN, s.arr[i], NO_COLOR);
	else
		printf("%d", s.arr[i]);
}

static void		options_and_operation(t_opt opt, char *op)
{
	if (opt.d)
		printf("DISPLAY MODE (INTERVAL OF %ds)", SLEEP_TIME / 1000000);
	else if (opt.v)
		printf("DEBUG MODE");
	if (opt.c)
		printf(" WITH %sCOLOURS%s", GREEN, NO_COLOR); 
	if (op && opt.c)
		printf("\n%s%s%s\n", GREEN, op, NO_COLOR);
	else if (op)
		printf("\n%s\n", op);
	else
		printf("\n");
}

void			print_stacks(t_main m, size_t size_max, char *op)
{
	int		i;

	i = -1;
	printf("%s%s", CURSOR_HOME, CLEAR_SCREEN);
	options_and_operation(*(m.opt), op);
	printf("a	b\n-	-\n");
	while (++i < (int)size_max)
	{
		if (i < (int)(m.a->size))
        {
            if (m.opt->c && op)
                colors_a(op, *(m.a), i);
            else
			    printf("%d", m.a->arr[i]);
        }
        else
			printf(" ");
		printf("\t");
		if (i < (int)m.b->size)
		{
			if (m.opt->c && op)
               colors_b(op, *(m.b), i);
            else
			    printf("%d", m.b->arr[i]);
		}
		printf("\n");
	}
	printf("-	-\n");
}