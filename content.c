/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:42:52 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/12 17:13:10 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_content(void *content)
{
	free(content);
}

int	get_content_value(t_list *list)
{
	return (*((int *)list->content));
}

int	is_arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
