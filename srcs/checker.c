/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/05 17:46:39 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*str_to_arr_i(char **av, int ac)
{
	int		i;
	int		*a;
	int		size;

	size = ac - 1;
	if (!(a = malloc(size * sizeof(int))))
		return (NULL);
	i = -1;
	while (av[++i + 1])
	{
		if (!(check_stack(av[i + 1])) || !(check_dup(av)))
			return (NULL);
		a[i] = ft_atoi(av[i + 1]);
	}
	return (a);
}

static int		read_inst_and_execute(t_stack *s)
{
	char	*inst;

	while (get_next_line(STDIN_FILENO, &inst) > 0)
		if (!(execute_instructions(s, inst)))
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_stack	s;

	if (ac < 2)
		return (0);
	if (!(s.a = str_to_arr_i(av, ac)))
		return (error(&s));
	s.size_a = ac - 1;
	// ft_print_array_i(s.a, s.size_a, "a");
	s.size_b = 0;
	s.size_max = s.size_a;
	if (!(s.b = malloc((s.size_max + 1) * sizeof(int))))
		return (error(&s));
	if (!(read_inst_and_execute(&s)))
		return (error(&s));
	if (stack_is_sort(s.a, s.size_a) && s.size_b == 0)
		ft_putstr(OK);
	else
		ft_putstr(KO);
	free(s.a);
	free(s.b);
	return (0);
}