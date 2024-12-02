/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:49:16 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/15 13:15:00 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	d = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (*s2 == d)
		{
			return (s2);
		}
		s2++;
		i++;
	}
	return (NULL);
}
