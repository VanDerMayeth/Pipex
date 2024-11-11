/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:46:28 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/15 17:52:04 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenofint(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa_2(void)
{
	char	*str;

	str = (char *)malloc((2) * sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*prueba(int len, char *str)
{
	if (len == 0 && *(str + 1) != '\0')
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	if (n == 0)
		return (ft_itoa_2());
	len = ft_lenofint(n);
	nbr = (long)n;
	str = malloc((len + 1) * sizeof(char));
	if (nbr < 0)
		nbr = -nbr;
	if (!str)
		return (0);
	*(str + len--) = '\0';
	while (nbr)
	{
		*(str + len--) = nbr % 10 +48;
		nbr /= 10;
	}
	if (len == 0 && *(str + 1) == '\0')
		str[0] = '0';
	str = prueba(len, str);
	if (n == 0)
		return ("0");
	return (str);
}
