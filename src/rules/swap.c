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

int	do_sa(t_list **a, t_list **b)
{
	t_list	*temp;

	(void)b;
	if (!a || !(*a) || !(*a)->next)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	return (1);
}

int	do_sb(t_list **a, t_list **b)
{
	t_list	*temp;

	(void)a;
	if (!b || !(*b) || !(*b)->next)
		return (0);
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	return (1);
}

int	do_ss(t_list **a, t_list **b)
{
	int	result_sa;
	int	result_sb;

	result_sa = do_sa(a, b);
	result_sb = do_sb(a, b);
	if (result_sa && result_sb)
		return (1);
	return (0);
}
