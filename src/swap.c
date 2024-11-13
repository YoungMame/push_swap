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

static void	swap(t_list **list)
{
	t_list	*temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = *list;
	*list = (*list)->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
	return ;
}

void	do_sa(t_list **a, t_list **b)
{
	(void)b;
	swap(a);
	ft_printf("sa\n");
	return ;
}

void	do_sb(t_list **a, t_list **b)
{
	(void)a;
	swap(b);
	ft_printf("sb\n");
	return ;
}

void	do_ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return ;
}
