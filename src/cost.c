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

static int	ft_lstindex(t_list *list, t_list *ptr)
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

int	get_reverse_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstindex(list, target));
}

int	get_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstsize(list) - ft_lstindex(list, target));
}
