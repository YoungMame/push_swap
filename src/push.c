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

static void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = (*a);
	(*a) = temp;
	return ;
}

void	do_pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pa\n");
	return ;
}

void	do_pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pb\n");
	return ;
}
