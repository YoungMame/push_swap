/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:36:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 17:54:36 by mduvey           ###   ########.fr       */
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

static void	parse_error(t_list **list, char **parsed_args)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(list, &free_stack_content);
	while (parsed_args)
	{
		free(parsed_args[i]);
		i++;
	}
	return ;
}

char	**get_args(char **args, int argc)
{
	char	**parsed_args;

	if (argc == 2)
		parsed_args = ft_split(args[1], ' ');
	else
		parsed_args = ++args;
	return (parsed_args);
}

int	parse(char **args, int argc, t_list **a)
{
	int		i;
	long	*content;
	char	**parsed_args;

	parsed_args = get_args(args, argc);
	i = 0;
	content = NULL;
	while (parsed_args[i])
	{
		content = malloc(sizeof(long));
		*content = ft_atol(parsed_args[i]);
		if ((*a && is_existing(*content, *a))
			|| !(INT_MIN < *content && *content < INT_MAX))
			return (parse_error(a, parsed_args), 0);
		ft_lstadd_back(a, ft_lstnew((void *)content));
		i++;
	}
	i = 0;
	while (parsed_args[i])
	{
		free(parsed_args[i]);
		i++;
	}
	return (1);
}
