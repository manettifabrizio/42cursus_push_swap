/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/30 17:24:23 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		read_and_execute(t_main *m)
{
	char	*op;

	if (m->opt->d)
	{
		printf("%s%s", CURSOR_HOME, CLEAR_SCREEN);
		usleep(SLEEP_TIME);
		print_stacks(*m, *(m->a), *(m->b));
	}
	while (get_next_line(STDIN_FILENO, &op) > 0)
	{
		(m->ops_nbr)++;
		if (!(execute(m, op)))
			return (0);
	}
	return (1);
}

static int		check_options(char *s, t_opt *opt)
{
	int		i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'd')
			opt->d = 1;
		else if (s[i] == 'c')
			opt->c = 1;
		else if (s[i] == 'v')
			opt->v = 1;
		else if (s[i] == 'o')
			opt->o = 1;
		else
			return (0);
	}
	if (i == 1)
		return (0);
	else
		return (1);
}

static int		options(t_main *m, char *s)
{
	m->opt = NULL;
	if (!(m->opt = malloc(sizeof(t_opt))))
		return (0);
	m->opt->d = 0;
	m->opt->c = 0;
	m->opt->v = 0;
	m->opt->o = 0;
	if (s[0] == '-' && ft_isalpha(s[1]))
		if (!(m->is_opt = check_options(s, m->opt)))
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_main	m;

	if (ac < 2)
		return (0);
	m.ops_nbr = 0;
	m.a = NULL;
	m.b = NULL;
	if (!(options(&m, av[1])))
		return (error(&m));
	if (!(create_stacks(&m, av)) || !(read_and_execute(&m)))
		return (error(&m));
	if (stack_is_sort(*(m.a)) && m.b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	if (m.opt->o)
		printf("Total number of operations: %d\n", m.ops_nbr);
	free(m.a->arr);
	free(m.b->arr);
	return (0);
}