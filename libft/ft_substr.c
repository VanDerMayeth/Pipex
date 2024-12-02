/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:11:01 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/14 18:51:27 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_1(char	*dst)
{
	dst = malloc(1);
	if (dst == NULL)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	dst = NULL;
	if (start > slen)
	{
		dst = ft_substr_1(dst);
		return (dst);
	}
	if (start + len > slen)
		len = slen - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (len-- > 0)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
