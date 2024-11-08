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

int	do_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	temp->next = (*a);
	(*a) = temp;
	return (1);
}

int	do_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	temp->next = (*b);
	(*b) = temp;
	return (1);
}
