/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:33:30 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/07 18:42:42 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list	**list)
{
	t_list	*last;
	t_list	*temp;

	last = *list;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	temp->next = *list;
	*list = temp;
	last->next = NULL;
	return ;
}

void	do_rra(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	return ;
}

void	do_rrb(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	return ;
}

void	do_rrr(t_list **a, t_list **b)
{
	if (a && *a)
		reverse_rotate(a);
	if (b && *b)
		reverse_rotate(b);
	ft_printf("rrr\n");
	return ;
}
