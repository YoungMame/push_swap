/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:20:36 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:16:54 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	size = 1;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}
