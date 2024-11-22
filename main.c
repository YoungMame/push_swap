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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		error;

	a = NULL;
	b = NULL;
	error = (parse(argv, argc, &a) == 0);
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
	ft_lstclear(&a, &free_stack_content);
	ft_lstclear(&b, &free_stack_content);
	return (0);
}

// static void	show_list(t_list *a, t_list *b)
// {
// 	int		index;

// 	index = 0;
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			printf("%i, ", *((int *)a->content));
// 			a = a->next;
// 		}
// 		else
// 			printf(" null");
// 		if (b)
// 		{
// 			printf("%i, ", *((int *)b->content));
// 			b = b->next;
// 		}
// 		else
// 			printf(" null");
// 		printf("\n");
// 		index++;
// 	}
// 	printf("a  |  b\n");
// 	return ;
// }
