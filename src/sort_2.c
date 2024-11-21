/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:32 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/21 16:06:35 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function sort a stack of 3
// patterns
// 1 : 2 1 3
// 2 : 3 2 1
// 3 : 2 3 1
// 4 : 3 1 2
static void	sort_stacks_3(t_list **a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = get_content_value(*a);
	val2 = get_content_value((*a)->next);
	val3 = get_content_value((*a)->next->next);

	if (val1 > val2 && val2 < val3 && val3 > val1)   // 2 1 3
		do_sa(a);
	else if (val1 > val2 && val2 > val3)    // [3 2 1]
	{
		do_sa(a);
		do_ra(a);
	}
	else if (val1 < val2 && val2 > val3)     // 2 3 1
		do_ra(a);
	else if (val1 > val2 && val2 < val3)    // 3 1 2
		do_ra(a);
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
		temp_target = get_bigger(*a, get_content_value(*b));
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
