/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:41:59 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 17:42:11 by mduvey           ###   ########.fr       */
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

int	handle_ope(char *ope, t_list **a_check, t_list **b_check)
{
	if (!ope)
		return (0);
	if (ft_strncmp(ope, "pa\n", ft_strlen(ope)) == 0)
		do_pa(a_check, b_check);
	if (ft_strncmp(ope, "pb\n", ft_strlen(ope)) == 0)
		do_pb(a_check, b_check);
	if (ft_strncmp(ope, "sa\n", ft_strlen(ope)) == 0)
		do_sa(a_check);
	if (ft_strncmp(ope, "sb\n", ft_strlen(ope)) == 0)
		do_sb(b_check);
	if (ft_strncmp(ope, "ra\n", ft_strlen(ope)) == 0)
		do_ra(a_check);
	if (ft_strncmp(ope, "rra\n", ft_strlen(ope)) == 0)
		do_rra(a_check);
	if (ft_strncmp(ope, "rb\n", ft_strlen(ope)) == 0)
		do_rb(b_check);
	if (ft_strncmp(ope, "rrb\n", ft_strlen(ope)) == 0)
		do_rrb(b_check);
	if (ft_strncmp(ope, "rr\n", ft_strlen(ope)) == 0)
		do_rr(a_check, b_check);
	if (ft_strncmp(ope, "rrr\n", ft_strlen(ope)) == 0)
		do_rrr(a_check, b_check);
	return (1);
}

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

int	main(int argc, char **argv)
{
	t_list	*a_check;
	t_list	*b_check;
	int		error;
	char	*line;
	int		is_running;

	a_check = NULL;
	b_check = NULL;
	error = (parse(argv, argc, &a_check) == 0);
	if (error)
		return (1);
	line = NULL;
	is_running = 1;
	while (is_running)
	{
		line = ft_get_next_line(0);
		if (!line)
			break ;
		is_running = handle_ope(line, &a_check, &b_check);
		free(line);
	}
	show_list(a_check, b_check);
	if (is_sorted(a_check) && ft_lstsize(b_check) == 0)
		return (ft_printf("OK\n"), 1);
	else
		return (ft_printf("KO\n"), 1);
}
