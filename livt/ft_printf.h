/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:52:12 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:41:13 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *input_str, ...);
int		ft_write_p(void *arg);
int		ft_write_s(char *arg);
int		ft_write_c(char arg);
int		ft_write_d_i(int arg);
int		ft_write_u(unsigned int arg);
int		ft_write_hex(unsigned int num, int fmt);

#endif