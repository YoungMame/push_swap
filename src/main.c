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

static void	show_list(t_list *a, t_list *b)
{
	int		index;

	index = 0;
	while (a || b)
	{
		if (a)
		{
			printf("%i, ", *((int *)a->content));
			a = a->next;
		}
		else
			printf(" null");
		if (b)
		{
			printf("%i, ", *((int *)b->content));
			b = b->next;
		}
		else
			printf(" null");
		printf("\n");
		index++;
	}
	printf("a  |  b\n");
	return ;
}

//we travel the stack for each node to find the cheapest move

void	sort_stacks(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;
	t_list	*choice;
	int		latest_cost;
	int		cheapest_cost;

	do_pb(a, b);
	do_pb(a, b);
	i = *a;
	while (i)
	{
		latest_cost = get_move_cost(*a, *b, i);
		if (latest_cost < cheapest_cost)
		{
			cheapest_cost = latest_cost;
			choice = i;
		}
		i = i->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*new_node;
	int		*content;

	i = 1;
	a = NULL;
	b = NULL;
	content = NULL;
	while (i < argc)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i]);
		new_node = ft_lstnew((void *)content);
		ft_lstadd_back(&a, new_node);
		i++;
	}
	// show_list(a, b);
	sort_stacks(&a, &b);
	// show_list(a, b);
	ft_lstclear(&a, &free_stack_content);
	return (1);
}