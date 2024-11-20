/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:35:35 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/20 17:47:17 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finalize_a(t_list **a)
{
	t_list	*target;

	target = get_smallest(*a);
	while (*a != target)
	{
		if (get_rotation_way(target, *a))
			do_ra(a);
		else if (get_rotation_way(target, *a) == 0)
			do_rra(a);
		else
			break ;
	}
	return ;
}

static	t_move	update_move(int cost, t_list *source, t_list *target)
{
	t_move	move;

	move.cost = cost;
	move.target = target;
	move.source = source;
	return (move);
}

static t_move	find_best_move(t_list *src_list, t_list *tgt_list)
{
	t_list	*temp_source;
	t_list	*temp_target;
	t_move	move;
	int		latest_cost;

	move = update_move(INT_MAX, NULL, NULL);
	temp_source = src_list;
	temp_target = tgt_list;
	while (temp_source)
	{
		if (get_is_minimum(get_content_value(temp_source), tgt_list))
			temp_target = get_biggest(tgt_list);
		else
			temp_target = get_smaller(tgt_list, get_content_value(temp_source));
		latest_cost = get_move_cost(src_list,
						temp_source, tgt_list, temp_target);
		if (latest_cost < move.cost)
			move = update_move(latest_cost, temp_source, temp_target);
		temp_source = temp_source->next;
	}
	return (move);
}

static	void	fill_b(t_list **a, t_list **b, t_move move)
{
	while (*a != move.source && *b != move.source)
	{
		if (get_rotation_way(move.source, *a) == 1
			&& get_rotation_way(move.target, *b) == 1)
			do_rr(a, b);
		else if (get_rotation_way(move.source, *a) == 0
			&& get_rotation_way(move.target, *b) == 0)
			do_rrr(a, b);
		else
			break ;
	}
	if (get_rotation_way(move.source, *a) == 1)
		while (*a != move.source)
			do_ra(a);
	else
		while (*a != move.source)
			do_rra(a);
	if (get_rotation_way(move.target, *b) == 1)
		while (*b != move.target)
			do_rb(b);
	else
		while (*b != move.target)
			do_rrb(b);
	do_pb(a, b);
	return ;
}

void	sort_stacks(t_list **a, t_list **b)
{
	do_pb(a, b);
	do_pb(a, b);
	while (*a)
		fill_b(a, b, find_best_move(*a, *b));
	while (*b)
		do_pa(a, b);
	finalize_a(a);
	return ;
}
