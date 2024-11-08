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

int	do_ra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	last = *a;
	while (last->next)
		last = last->next;
	temp = *a;
	last->next = *a;
	*a = (*a)->next;
	temp->next = NULL;
	return (1);
}

int	do_rb(t_list **b)
{
	t_list	*temp;
	t_list	*last;

	last = *b;
	while (last->next)
		last = last->next;
	temp = *b;
	last->next = *b;
	*b = (*b)->next;
	temp->next = NULL;
	return (1);
}

int	do_rr(t_list **a, t_list **b)
{
	int	result_sa;
	int	result_sb;

	result_sa = do_ra(a);
	result_sb = do_rb(b);
	if (result_sa && result_sb)
		return (1);
	return (0);
}
