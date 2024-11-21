/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:36:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:36:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_list *list)
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

int	parse(char **args, t_list **a)
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
