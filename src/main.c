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

int	is_minimum(int n, t_list *b)
{
	while (b && b->content)
	{
		if (get_content_value(b) < n)
			return (0);
		b = b->next;
	}
	return (1);
}

int	sort_in_b(t_list **a, t_list **b)
{
	t_list	*biggest_o_smallest_ptr;
	if (is_minimum(get_content_value(*a), *b))
	{
		biggest_o_smallest_ptr = get_biggest(*b);
		while (*b != biggest_o_smallest_ptr)
			do_rb(b);
		do_pb(a, b);
		do_rrb(b);
	}
	else
	{
		biggest_o_smallest_ptr = get_smaller(*b, get_content_value(*a));
		while (*b != biggest_o_smallest_ptr)
			do_rb(b);
		do_pb(a, b);
	}
	return (1);
}

int	sort_stack(t_list **a, t_list **b)
{
	t_list	*biggest_ptr;

	if (!*b)
		do_pb(a, b);
	while (a && *a)
		sort_in_b(a, b);
	while (a && *a)
		sort_in_b(a, b);
	biggest_ptr = get_biggest(*b);
	while (*b != biggest_ptr)
		do_rb(b);
	while (b && *b)
		do_pa(a, b);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_list	*new_node;
	int		*content;

	i = 1;
	content = NULL;
	while (i < argc)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i]);
		new_node = ft_lstnew((void *)content);
		ft_lstadd_front(&a, new_node);
		i++;
	}
	show_list(a, b);
	sort_stack(&a, &b);
	printf("Stacks after sorting \n");
	printf("----------------------------\n");
	show_list(a, b);
	ft_lstclear(&a, &free_stack_content);
	return (1);
}
