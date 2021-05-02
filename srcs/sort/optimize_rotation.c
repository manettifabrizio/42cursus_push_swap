/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:25:28 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/02 23:22:43 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		replace_elems(t_list **elem, int skip, int x, char *s)
{
	int		y;
	t_list	*l;
	t_list	*tmp;

	while (*elem && skip--)
		(*elem) = (*elem)->next;
	y = x;
	while (y--)
	{
		(*elem)->content = s;
		if (y > 0)
			(*elem) = (*elem)->next;
	}
	l = (*elem)->next;
	while (l && x--)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
	(*elem)->next = l;
}

static void		search_duplicates(t_list **elem, char *s1, char *s2, char *s3)
{
	int		x;
	int		y;
	t_list	*l;

	x = 0;
	l = *elem;
	while (ft_strcmp(l->content, s1) == 0)
	{
		x++;
		l = l->next;
	}
	y = 0;
	while (ft_strcmp(l->content, s2) == 0)
	{
		y++;
		l = l->next;
	}
	if (x <= y && x != 0 && y != 0)
		replace_elems(elem, 0, x, s3);
	if (x > y && x != 0 && y != 0)
		replace_elems(elem, x - y, y, s3);
}

void			optimize_rotation(t_list **h)
{
	t_list	*l;

	l = *h;
	while (l)
	{
		if (ft_strcmp(l->content, ROTATE_A) == 0)
			search_duplicates(&l, ROTATE_A, ROTATE_B, ROTATE_AB);
		else if (ft_strcmp(l->content, ROTATE_B) == 0)
			search_duplicates(&l, ROTATE_B, ROTATE_A, ROTATE_AB);
		else if (ft_strcmp(l->content, REV_ROTATE_A) == 0)
			search_duplicates(&l, REV_ROTATE_A, REV_ROTATE_B, REV_ROTATE_AB);
		else if (ft_strcmp(l->content, REV_ROTATE_B) == 0)
			search_duplicates(&l, REV_ROTATE_B, REV_ROTATE_A, REV_ROTATE_AB);
		l = l->next;
	}
}
