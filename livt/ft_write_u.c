/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:22:55 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:25:05 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uint_to_str(char *str, unsigned int num, int len)
{
	unsigned int	aux;

	aux = (unsigned int) num;
	while (aux != 0)
	{
		str[--len] = '0' + (aux % 10);
		aux = aux / 10;
	}
	return (str);
}

static char	*ft_newstr_uint(unsigned int num)
{
	int					i;
	unsigned int		aux;
	char				*dest;

	i = 0;
	aux = num;
	while (aux != 0)
	{
		aux = aux / 10;
		i++;
	}
	dest = (char *) malloc (i + 1);
	if (dest == NULL)
		return (0);
	dest[i] = '\0';
	dest = ft_uint_to_str(dest, num, i);
	return (dest);
}

int	ft_write_u(unsigned int arg)
{
	int		i;
	int		num;
	char	*str;

	i = 0;
	if (arg == 0)
	{
		return (write(1, "0", 1));
	}
	num = (unsigned int) arg;
	str = ft_newstr_uint(num);
	if (str == NULL)
		return (-1);
	i = ft_write_s(str);
	free(str);
	return (i);
}
