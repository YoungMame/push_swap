/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:32 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/21 17:20:05 by mduvey           ###   ########.fr       */
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
	if (val1 > val2 && val2 < val3 && val3 > val1)
		do_sa(a);
	else if (val1 > val2 && val2 > val3)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (val1 < val2 && val2 > val3)
		do_ra(a);
	else if (val1 > val2 && val2 < val3)
		do_ra(a);
	return ;
}

void	sort_stacks_5(t_list **a, t_list **b)
{
	t_list	*temp_target;
	int		value;

	while (ft_lstsize(*a) > 3)
		do_pb(a, b);
	sort_stacks_3(a);
	while (*b)
	{
		value = get_content_value(*b);
		ft_printf("Cas particulier = %i, ", value);
		if (get_is_maximum(value, *a))
			temp_target = get_smallest(*a);
		else
			temp_target = get_bigger(*a, value);
		ft_printf("sa target est = %i\n", *temp_target);
		while (*a != temp_target)
		{
			if (get_rotation_way(temp_target, *a))
				do_ra(a);
			else if (get_rotation_way(temp_target, *a) == 0)
				do_rra(a);
		}
		do_pa(a, b);
	}
	temp_target = get_smallest(*a);
	while (*a != temp_target)
		do_ra(a);
}
