/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:44:21 by igorda-c          #+#    #+#             */
/*   Updated: 2024/03/07 15:46:55 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlcpy_1(char *dst, char *src, size_t dstsize);
size_t	ft_strlen_1(char *s);
char	*ft_strjoin_1(char *s1, char *s2);
char	*ft_strdup_1(char *s1);
char	*ft_strchr_1(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_free(char **str);
#endif