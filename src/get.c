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
