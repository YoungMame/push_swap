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

//the goal of this function is to calculate every moves that are possble
// we use it to compare every move cost and execute the cheaper

int	get_move_cost(t_list **a, t_list *source, t_list **b)
{
	int		total;
	t_list *target;

	total = 0;
	if (get_rotation_way(source, *a) == 1)
	{
		total += get_rotation_cost(source, *a);
	}
	else
	{
		total += get_reverse_rotation_cost(source, *a);
	}
	if (!get_is_minimum(get_content_value(source), *b))
	{
		target = get_smaller(*b, get_content_value(source));
		if (get_rotation_way(target, *b) == 1)
		{
			total += get_rotation_cost(target, *b);
		}
		else
		{
			total += get_reverse_rotation_cost(target, *b);
		}
	}
	return (total + 1);
}

int	get_reverse_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstindex(list, target));
}

int	get_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstsize(list) - ft_lstindex(list, target));
}
