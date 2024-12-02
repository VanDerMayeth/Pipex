/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:49:08 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:39 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_c(char arg)
{
	int	i;

	i = write(1, &arg, 1);
	return (i);
}

int	ft_write_s(char *arg)
{
	int	i;
	int	err;

	i = 0;
	if (arg == NULL)
	{
		i = write(1, "(null)", 6);
	}
	else
	{
		while (arg[i] != '\0')
		{
			err = write(1, &arg[i++], 1);
			if (err == -1)
				return (err);
		}
	}
	return (i);
}

static int	ft_write_else(char const *str, void *arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i = ft_write_c(*(char *)arg);
	else if (*str == 's')
		i = ft_write_s((char *) arg);
	else if (*str == 'p')
		i = ft_write_p(arg);
	else if (*str == 'd')
		i = ft_write_d_i(*(int *)arg);
	else if (*str == 'i')
		i = ft_write_d_i(*(int *)arg);
	else if (*str == 'u')
		i = ft_write_u(*(unsigned int *)arg);
	else if (*str == 'x' || *str == 'X')
		i = ft_write_hex(*(unsigned int *)arg, (int) *str);
	return (i);
}

int	ft_printf(char const *input_str, ...)
{
	int		i;
	int		err;
	va_list	args;

	i = 0;
	va_start(args, input_str);
	while (*input_str != '\0')
	{
		if (*input_str != '%')
			err = write(1, input_str, 1);
		else
		{
			++input_str;
			if (*input_str == '%')
				err = write(1, "\045", 1);
			else
				err = ft_write_else(input_str, va_arg(args, void *));
		}
		if (err == (-1))
			return (-1);
		i += err;
		++input_str;
	}
	va_end(args);
	return (i);
}
