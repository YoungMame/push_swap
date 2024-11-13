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

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

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

int	get_r_cost(t_list *target, t_list *source, t_list **list)
{
	int		count;
	t_list	*start;
	int		target_index;
	int		source_index;

	count = 0;
	start = source;
	while (target != source)
	{
		count++;
		if (source->next)
			source = source->next;
		else
			source = start;
	}
	target_index = ft_abs(ft_lstindex(target, *list));
	source_index = ft_abs(ft_lstindex(source, *list));
	ft_printf("target_index = %i (valeur = %i)\n", target_index, get_content_value(target));
	ft_printf("source_index = %i (valeur = %i)\n", source_index, get_content_value(source));
	if ((target_index - source_index) < count)
		return (0);
	else
		return (1);
}
