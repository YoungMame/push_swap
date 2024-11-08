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

static void	show_list(t_list *a)
{
	int		a_index = 0;

	while (a)
	{
		printf("content of a[%i] = %i\n", a_index, *(int *)a->content);
		a = a->next;
		a_index++;
	}
	return ;
}

int	main()
{
	int		i;
	int		*content;
	t_list	*a = NULL;

	srand(time(NULL));
	i = 0;
	while (i < 4)
	{
		content = malloc(sizeof(int));
		*content = rand() % 100;

		t_list	*new_node = ft_lstnew(content);
		ft_lstadd_front(&a, new_node);
		i++;
	}
	show_list(a);
	do_sa(&a);
	printf("Stack after do_sa \n");
	printf("----------------------------\n");
	show_list(a);
	return (1);
}