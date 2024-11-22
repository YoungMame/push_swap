/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:09:34 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/22 12:09:34 by mduvey           ###   ########.fr       */
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

static int	are_args_valid(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args && args[i])
	{
		j = 0;
		while (args[i] && args[i][j])
		{
			if (!ft_isdigit(args[i][j]) && args[i][j] != ' ')
				return (0);
			i++;
		}
	}
	return (1);
}

static void	parse_free(t_list **list, char **parsed_args, int error)
{
	int	i;

	i = 0;
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(list, &free_stack_content);
	}
	while (parsed_args && parsed_args[i])
	{
		free(parsed_args[i]);
		i++;
	}
	free(parsed_args);
	return ;
}

static char	**get_args(char **args, int argc, int *error)
{
	int		i;
	char	**parsed_args;

	i = 0;
	if (argc == 2)
		parsed_args = ft_split(args[1], ' ');
	else
	{
		parsed_args = malloc(sizeof(char *) * argc);
		if (!parsed_args)
			return (*error = 1, NULL);
		i = 0;
		while (args[i + 1])
		{
			parsed_args[i] = ft_strdup(args[i + 1]);
			if (!parsed_args[i])
				return (*error = 1, parsed_args);
			i++;
		}
		parsed_args[i] = NULL;
	}
	return (parsed_args);
}

int	parse(char **args, int argc, t_list **a)
{
	int		i;
	int		error;
	long	*content;
	char	**parsed_args;

	error = 0;
	parsed_args = get_args(args, argc, &error);
	if (error | !are_args_valid(args))
		return (parse_free(a, parsed_args, 1), 0);
	i = -1;
	content = NULL;
	while (parsed_args && parsed_args[++i])
	{
		content = malloc(sizeof(long));
		if (!content)
			return (parse_free(a, parsed_args, 1), 0);
		*content = ft_atol(parsed_args[i]);
		if ((*a && is_existing(*content, *a))
			|| !(INT_MIN < *content && *content < INT_MAX))
			return (free(content), parse_free(a, parsed_args, 1), 0);
		ft_lstadd_back(a, ft_lstnew((void *)content));
	}
	return (parse_free(a, parsed_args, 0), 1);
}
