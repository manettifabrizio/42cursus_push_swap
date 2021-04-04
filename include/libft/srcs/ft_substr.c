/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:46:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/03/31 14:16:58 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	size_t			i;
	unsigned int	x;

	i = 0;
	if (!s)
		return (NULL);
	x = ft_strlen(s);
	if (!(s2 = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start > x)
		return (ft_strdup(""));
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
