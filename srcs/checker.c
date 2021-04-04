/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/04 12:43:18 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_errors(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!(ft_isdigit(s[i]) || ft_isspace(s[i])))
		{
			ft_putstr_fd("\033[0;31mError\033[0m\n", STDERR_FILENO);
			return (1);
		}
	return (0);
}

int		*str_to_arr_i(char *s, size_t *len)
{
	int		i;
	int		*a;
	char	**tmp;

	if (check_errors(s))
		return (NULL);
	tmp = ft_split(s, ' ');
	*len = ft_arrlen(tmp);
	if (!(a = malloc((*len + 1) * sizeof(int))))
		return (NULL);
	i = -1;
	while (tmp[++i])
		a[i] = ft_atoi(tmp[1]);
	a[i] = 0;
	ft_free_array(tmp);
	return (a);
}

// void	reading()
// {
// 	char	buf[3];
	
// }

int		main(int ac, char **av)
{
	int		*a;
	int		*b;
	size_t	len;

	if (ac != 2)
		return (0);
	len = 0;
	if (!(a = str_to_arr_i(av[1], &len)))
		return (0);
	if (!(b = malloc((len + 1) * sizeof(int))))
		return (0);
	// while (reading())
	free(a);
	free(b);
	return (0);
}