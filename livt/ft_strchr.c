/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:29 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/14 13:49:51 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		x;

	x = 0;
	str = (char *)s;
	while (x <= (ft_strlen(str)))
	{
		if (str[x] == (unsigned char)c)
			return (&str[x]);
		x++;
	}
	return (NULL);
}
