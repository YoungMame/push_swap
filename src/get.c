/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:10:37 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/12 17:12:13 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//with this function we are looking for the best rotation
//target is the value we want to be the first element of our stack
// 1 is rotate and 2 is reverse rotate

int	get_rotation_way(t_list *target, t_list *list)
{
	int		target_index;
	int		list_size;

	list_size = ft_lstsize(list);
	target_index = ft_lstindex(target, list);
	if (target_index <= (list_size - target_index))
		return (1);
	return (2);
}

t_list	*get_biggest(t_list *list)
{
	t_list	*biggest_ptr;
	int		biggest;
	int		number;

	biggest_ptr = list;
	while (list)
	{
		number = get_content_value(list);
		biggest = get_content_value(biggest_ptr);
		if (number > biggest)
			biggest_ptr = list;
		list = list->next;
	}
	return (biggest_ptr);
}

int	get_is_minimum(int n, t_list *b)
{
	while (b && b->content)
	{
		if (get_content_value(b) < n)
			return (0);
		b = b->next;
	}
	return (1);
}

t_list	*get_smaller(t_list *list, int target)
{
	t_list	*smaller_ptr;
	int		current;

	smaller_ptr = list;
	while (list)
	{
		current = get_content_value(list);
		if (current <= target)
		{
			if (get_content_value(smaller_ptr) > target)
				smaller_ptr = list;
			else if (current > get_content_value(smaller_ptr))
				smaller_ptr = list;
		}
		list = list->next;
	}
	return (smaller_ptr);
}
