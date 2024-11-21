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

static void	rotate(t_list **list)
{
	t_list	*temp;
	t_list	*last;

	last = *list;
	while (last->next)
		last = last->next;
	temp = *list;
	last->next = *list;
	*list = (*list)->next;
	temp->next = NULL;
	return ;
}

void	do_ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
	return ;
}

void	do_rb(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
	return ;
}

void	do_rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return ;
}
