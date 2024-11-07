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

#include "include/push_swap.h"

static void	show_a(t_list *a)
{
	int		a_index = 0;

	while (a)
	{
		printf("value of a[%i] = %i", a_index, a->value);
		a = a->next;
		a_index++;
	}
}

static void	randomize_a(t_list *a)
{
	int		a_index = 0;
	char	*value;

	while (a)
	{
		a->value = a_index;
		a = a->next;
		a_index += 3;
	}
}

int	main()
{
	t_list *a;

	
	a = malloc(sizeof(t_list) * 1);
	//print
	int		a_index = 0;
	int		b_index = 0;
	while (a)
	{
		printf("value of a[%i] = %i", a_index, a->value);
		a = a->next;
	}
}