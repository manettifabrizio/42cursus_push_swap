/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:56:41 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/01 13:19:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_term_noncano(void)
{
	struct termios new;

	tcgetattr(STDERR_FILENO, &new);
	new.c_lflag &= ~(ICANON | ISIG | ECHO);
	tcsetattr(STDERR_FILENO, TCSADRAIN, &new);
}

void			set_term_cano(struct termios *base_term)
{
	tcsetattr(STDERR_FILENO, TCSADRAIN, base_term);
}

static int		copy_array(char **dst, char **src)
{
	int	i;

	i = -1;
	while (src[++i])
		if (!(dst[i] = ft_strdup(src[i])))
		{
			ft_free_array(dst);
			return (0);
		}
	dst[i] = NULL;
	return (1);
}

char			**add_elem_to_arr(char **a, char *op)
{
	int		size;
	char	**tmp;

	if (!a)
	{
		if (!(tmp = malloc(2 * sizeof(char*))))
			return (NULL);
		tmp[0] = op;
		tmp[1] = NULL;
	}
	else
	{
		size = ft_arrlen(a);
		if (!(tmp = malloc((size + 2) * sizeof(char*))))
			return (NULL);
		copy_array(tmp, a);
		tmp[size] = op;
		tmp[size + 1] = NULL;
		ft_free_array(a);
	}
	return (tmp);
}