/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:30:44 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/14 16:31:10 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (destsize < 1)
		return (count);
	while (src[i] && i < destsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (destsize)
		dst[i] = '\0';
	return (count);
}
