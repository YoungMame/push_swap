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
			printf("%i, ", *(int *)a->content);
		else
			printf(" null");
		if (b)
			printf("%i, ", *(int *)b->content);
		else
			printf(" null");
		printf("\n");
		a = a->next;
		b = b->next;
		index++;
	}
	printf("a  |  b\n");
	return ;
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
	do_rrr(&a, &b);
	printf("Stacks after do_ss \n");
	printf("----------------------------\n");
	show_list(a, b);
	return (1);
}