/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:40 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:24:48 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_int_to_str(char *str, int num, int len)
{
	int	aux;
	int	sign;

	sign = 1;
	aux = (int) num;
	if (aux < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	while (aux != 0)
	{
		str[--len] = '0' + (sign * aux % 10);
		aux = aux / 10;
	}
	return (str);
}

static char	*ft_newstr_int(int num)
{
	int		i;
	int		aux;
	char	*dest;

	i = 0;
	aux = num;
	if (aux < 0)
		i++;
	while (aux != 0)
	{
		aux = aux / 10;
		i++;
	}
	dest = (char *) malloc (i + 1);
	if (dest == NULL)
		return (0);
	dest[i] = '\0';
	dest = ft_int_to_str(dest, num, i);
	return (dest);
}

int	ft_write_d_i(int arg)
{
	int		i;
	int		num;
	char	*str;

	i = 0;
	if (arg == 0)
	{
		return (write(1, "0", 1));
	}
	num = (int) arg;
	if (num == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	str = ft_newstr_int(num);
	if (str == NULL)
		return (-1);
	i = ft_write_s(str);
	free(str);
	return (i);
}
