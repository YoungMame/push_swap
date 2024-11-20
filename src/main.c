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

static	int	is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (get_content_value(list->next) < get_content_value(list))
			return (0);
		list = list->next;
	}
	return (1);
}

static void	parse_error(t_list **list)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(list, &free_stack_content);
	return ;
}

static int	parse(char **args, t_list **a)
{
	int		i;
	long	*content;

	i = 1;
	content = NULL;
	while (args[i])
	{
		content = malloc(sizeof(long));
		*content = ft_atol(args[i]);
		if ((*a && is_existing(*content, *a))
			|| !(INT_MIN < *content && *content < INT_MAX))
			return (parse_error(a), 0);
		ft_lstadd_back(a, ft_lstnew((void *)content));
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		error;

	a = NULL;
	b = NULL;
	error = (parse(argv, &a) == 0);
	(void)argc;
	if (ft_lstsize(a) && !error && !is_sorted(a))
	{
		if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 3)
			sort_stacks_5(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	if (error)
		return (1);
	show_list(a, b);
	return (0);
}
