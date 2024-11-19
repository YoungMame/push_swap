/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:42:52 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/07 18:57:35 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	show_list(t_list *a, t_list *b)
// {
// 	int		index;

// 	index = 0;
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			printf("%i, ", *((int *)a->content));
// 			a = a->next;
// 		}
// 		else
// 			printf(" null");
// 		if (b)
// 		{
// 			printf("%i, ", *((int *)b->content));
// 			b = b->next;
// 		}
// 		else
// 			printf(" null");
// 		printf("\n");
// 		index++;
// 	}
// 	printf("a  |  b\n");
// 	return ;
// }

//in this function we throw a in b, 
//this function also calculates the best rotation way

// static	int	is_sorted(t_list *list)
// {
// 	while (list && list->next)
// 	{
// 		if (get_content_value(list->next) < get_content_value(list))
// 			return (0);
// 		list = list->next;
// 	}
// 	return (1);
// }

static	void	fill_b(t_list **a, t_list **b, t_move move)
{
	while (*a != move.source && *b != move.source)
	{
		if (get_rotation_way(move.source, *a) == 1 && get_rotation_way(move.target, *b) == 1)
			do_rr(a, b);
		else if (get_rotation_way(move.source, *a) == 0 && get_rotation_way(move.target, *b) == 0)
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

// static	void	fill_a(t_list **a, t_list **b, t_move move)
// {
// 	while (*a != move.target && *b != move.source)
// 	{
// 		if (get_rotation_way(move.target, *a) == 1 && get_rotation_way(move.source, *b) == 1)
// 			do_rr(a, b);
// 		else if (get_rotation_way(move.target, *a) == 0 && get_rotation_way(move.source, *b) == 0)
// 			do_rrr(a, b);
// 		else
// 			break ;
// 	}
// 	if (get_rotation_way(move.target, *a) == 1)
// 		while (*a != move.target)
// 			do_ra(a);
// 	else
// 		while (*a != move.target)
// 			do_rra(a);
// 	if (get_rotation_way(move.source, *b) == 1)
// 		while (*b != move.source)
// 			do_rb(b);
// 	else
// 		while (*b != move.source)
// 			do_rrb(b);
// 	do_pa(a, b);
// 	return ;
// }

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

static t_move	find_best_move(t_list **source_l, t_list **target_l)
{
	t_list	*temp_source;
	t_list	*temp_target;
	t_move	move;
	int		latest_cost;

	move.source = NULL;
	move.target = NULL;
	move.cost = INT_MAX;
	temp_source = *source_l;
	temp_target = *target_l;
	while (temp_source)
	{
		if (get_is_minimum(get_content_value(temp_source), *target_l))
			temp_target = get_biggest(*target_l);
		else
			temp_target = get_smaller(*target_l, get_content_value(temp_source));
		latest_cost = get_move_cost(source_l, temp_source, target_l, temp_target);
		if (latest_cost < move.cost)
		{
			move.cost = latest_cost;
			move.source = temp_source;
			move.target = temp_target;
		}
		temp_source = temp_source->next;
	}
	return (move);
}

//in this function we get every moves cost and ->
//we execute the cheaper move

void	sort_stacks(t_list **a, t_list **b)
{
	do_pb(a, b);
	do_pb(a, b);
	while (*a)
		fill_b(a, b, find_best_move(a, b));
	while (*b)
		do_pa(a, b);
	finalize_a(a);
	return ;
}

static int	is_existing(int n, t_list *list)
{
	while (list)
	{
		if (get_content_value(list) == n)
			return (1);
		list = list->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*new_node;
	long	*content;
	int		error;

	i = 1;
	a = NULL;
	b = NULL;
	content = NULL;
	error = 0;
	while (i < argc && argv[i])
	{
		content = malloc(sizeof(long));
		*content = ft_atol(argv[i]);
		if (a && is_existing(*content, a) || !content)
			error = 1;
		new_node = ft_lstnew((void *)content);
		ft_lstadd_back(&a, new_node);
		i++;
	}
	if (ft_lstsize(a) && !error)
		sort_stacks(&a, &b);
	if (error)
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(&a, &free_stack_content);
	return (1);
}
