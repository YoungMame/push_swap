/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:39:57 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 16:59:35 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_lst;
	t_list	*result_lst;

	if (!lst || !f)
		return (NULL);
	first_lst = NULL;
	while (lst)
	{
		result_lst = malloc(sizeof(t_list));
		if (!result_lst)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&first_lst, result_lst);
		result_lst->content = (*f)(lst->content);
		result_lst->next = NULL;
		lst = lst->next;
	}
	return (first_lst);
}
