/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:42:12 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/15 19:07:41 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	x;
	char			*yup;

	x = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	yup = (char *)malloc(sizeof(char) * (len + 1));
	if (yup == NULL)
		return (NULL);
	while (s[x])
	{
		yup[x] = f(x, s[x]);
		x++;
	}
	yup[x] = '\0';
	return (yup);
}
