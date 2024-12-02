/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:24:51 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 16:25:55 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_zero_case(char *str)
{
	str[0] = '0';
	str[1] = 'x';
	str[2] = '0';
	str[3] = '\0';
	return (str);
}

static char	*ft_ulong_to_hexstr(char *str, unsigned long num)
{
	int				i;
	unsigned long	dir;

	i = 0;
	dir = num;
	if (dir == 0)
		return (handle_zero_case(str));
	while (dir > 0)
	{
		dir = dir / 16;
		i++;
	}
	i += 2;
	str[i] = '\0';
	dir = num;
	while (dir > 0)
	{
		i--;
		str[i] = "0123456789abcdef"[dir % 16];
		dir = dir / 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int	ft_write_p(void *arg)
{
	int				i;
	unsigned long	dir;
	char			*num;

	i = 0;
	if (arg == NULL)
		return (write(1, "0x0", 3));
	dir = (unsigned long) arg;
	while (dir > 0)
	{
		dir = dir / 16;
		i++;
	}
	num = (char *)malloc(i + 3);
	if (num == NULL)
		return (-1);
	dir = (unsigned long)arg;
	num = ft_ulong_to_hexstr(num, dir);
	i = write(1, num, i + 2);
	free(num);
	return (i);
}
