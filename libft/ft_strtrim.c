/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:03:34 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/15 14:25:37 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_look(char c, const char *set)
{
	int	x;
	int	len2;

	x = 0;
	len2 = ft_strlen(set);
	while (x < len2)
	{
		if (c == set[x])
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dst;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_look(s1[i], set))
		i++;
	while (len > 0 && ft_look(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	dst = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!dst)
		return (NULL);
	while (i < len)
		dst[j++] = (char)s1[i++];
	dst[j] = '\0';
	return (dst);
}
