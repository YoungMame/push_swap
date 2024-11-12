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

int	do_rra(t_list **a)
{
	t_list	*last;
	t_list	*temp;

	last = *a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	temp->next = *a;
	*a = temp;
	last->next = NULL;
	return (1);
}

int	do_rrb(t_list **b)
{
	t_list	*last;
	t_list	*temp;

	last = *b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	temp->next = *b;
	*b = temp;
	last->next = NULL;
	return (1);
}

int	do_rrr(t_list **a, t_list **b)
{
	int	result_sa;
	int	result_sb;

	if (a && *a)
		result_sa = do_rra(a);
	if (b && *b)
		result_sb = do_rrb(b);
	if (result_sa && result_sb)
		return (1);
	return (0);
}
