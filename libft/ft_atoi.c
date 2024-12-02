/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:19:35 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/12 22:43:07 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			x;
	long int	sign;
	long int	result;

	x = 0;
	sign = 1;
	result = 0;
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\v'
		|| str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
		x++;
	if (str[x] == '-' && str[x + 1] >= '0' && str[x + 1] <= '9')
		sign = -1;
	if (str[x] == '+' || str[x] == '-')
		x++;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (int)(str[x] - '0');
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
		x++;
	}
	return (result * sign);
}
