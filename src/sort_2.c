/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:32 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/20 18:56:53 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stacks_3(t_list **a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = get_content_value(*a);
	val2 = get_content_value((*a)->next);
	val3 = get_content_value((*a)->next->next);
	if (val1 > val2 && val2 > val3)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (val1 > val3 && val3 > val2)
		do_ra(a);
	else if (val2 > val1 && val1 > val3)
		do_sa(a);
	else if (val2 > val3 && val3 > val1)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (val3 > val1 && val1 > val2)
		do_rra(a);
	return ;
}


void	sort_stacks_5(t_list **a, t_list **b)
{
	t_list	*temp_target;

	while (ft_lstsize(*a) > 3)
		do_pb(a, b);
	sort_stacks_3(a);
	while (*b)
	{
		if (get_is_minimum(get_content_value(*b), *a))
			temp_target = get_biggest(*a);
		else
			temp_target = get_smaller(*a, get_content_value(*b));
		while (*a != temp_target)
		{
			if (get_rotation_way(temp_target, *a))
				do_ra(a);
			else
				do_rra(a);
		}
		do_pa(a, b);
	}
	temp_target = get_biggest(*a);
	while (*a == temp_target)
		do_ra(a);
	return ;
}
