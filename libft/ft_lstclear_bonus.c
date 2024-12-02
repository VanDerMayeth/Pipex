/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorda-c <igorda-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:57:57 by igorda-c          #+#    #+#             */
/*   Updated: 2024/02/08 15:24:28 by igorda-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*old;
	t_list	*new;

	if (!lst || !*lst)
		return ;
	old = *lst;
	while (old)
	{
		new = old->next;
		del(old->content);
		free(old);
		old = new;
	}
	*lst = NULL;
}
