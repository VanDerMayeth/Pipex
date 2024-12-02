/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:25:56 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/15 13:15:16 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;

	src2 = (char *)src;
	dst2 = dst;
	if ((dst == NULL && src == NULL) || len <= 0)
	{
		return (dst);
	}
	if (src2 < dst2)
	{
		src2 = src2 + (len -1);
		dst2 = dst2 +(len - 1);
		while (len-- > 0)
			*dst2-- = *src2--;
		return (dst);
	}
	while (len-- > 0)
		*dst2++ = *src2++;
	return (dst);
}
