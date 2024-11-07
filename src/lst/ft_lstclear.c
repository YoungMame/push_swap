/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:47:02 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/22 17:40:41 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*temp;

	if (!*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		temp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = temp;
		*lst = ptr;
	}
	return ;
}
