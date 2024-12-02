/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:07 by igorda-c          #+#    #+#             */
/*   Updated: 2023/12/19 20:54:18 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*yup;

	yup = *lst;
	if (!yup)
		*lst = new;
	else
	{
		while (yup->next)
			yup = yup->next;
		yup->next = new;
	}
}
