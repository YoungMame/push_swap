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

int	ft_lstindex(t_list *list, t_list *ptr)
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

int	get_move_cost(t_list **a, t_list *source, t_list **b, t_list *target)
{
	int		total_a;
	int		total_b;

	total_a = 0;
	total_b = 0;
	if (get_rotation_way(source, *a) == 1)
	{
		total_a += get_rotation_cost(source, *a);
	}
	else
	{
		total_a += get_reverse_rotation_cost(source, *a);
	}
	if (get_rotation_way(target, *b) == 1)
		total_b += get_rotation_cost(target, *b);
	else
		total_b += get_reverse_rotation_cost(target, *b);

	return (total_a + total_b + 1);
}

int	get_reverse_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstindex(list, target));
}

int	get_rotation_cost(t_list *target, t_list *list)
{
	return (ft_lstsize(list) - ft_lstindex(list, target));
}
