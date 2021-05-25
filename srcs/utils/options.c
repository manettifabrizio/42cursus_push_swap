/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:58:01 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/25 17:54:47 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (i == 1 || (opt->d && opt->v) || (opt->c && !opt->d && !opt->v))
		return (0);
	else
		return (1);
}

int				options(t_main *m, char *s)
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
