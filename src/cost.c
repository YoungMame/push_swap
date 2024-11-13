/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:23:12 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/13 18:25:42 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lstindex(t_list *ptr, t_list *list)
{
	int	index;

	index = 0;
	while (list && list != ptr)
	{
		index++;
		list = list->next;
	}
	return (index);
}

int	get_r_cost(t_list *target, t_list **list)
{
	int		target_index;
	int		list_size;

	list_size = ft_lstsize(*list);
	target_index = ft_lstindex(target, *list);
	if (target_index <= (list_size - target_index))
		return (1);
	return (0);
}
