/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:09:19 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/18 20:11:27 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*aux1;
	char	*aux2;

	if (!*needle)
		return ((char *)haystack);
	while (len -- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = len;
			aux1 = (char *)haystack + 1;
			aux2 = (char *)needle + 1;
			while (i -- && *aux1 && *aux2 && *aux1 == *aux2)
			{
				++aux1;
				++aux2;
			}
			if (!*aux2)
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
