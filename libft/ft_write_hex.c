/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:02:58 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 16:18:00 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(unsigned int num, int fmt)
{
	int				i;
	unsigned int	h;

	i = 0;
	h = num;
	if (h > 15)
	{
		i += ft_write_hex((h / 16), fmt);
		if (i == (-1))
			return (i);
	}
	if (fmt == 'x')
		i += ft_write_c("0123456789abcdef"[h % 16]);
	else
		i += ft_write_c("0123456789ABCDEF"[h % 16]);
	return (i);
}
