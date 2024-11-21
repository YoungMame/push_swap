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

int	handle_ope(char *ope, t_list **a_check, t_list **b_check)
{
	if (!ope)
		return (0);
	if (ft_strncmp(ope, "pa", ft_strlen(ope)) == 0)
		do_pa(a_check, b_check);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a_check;
	t_list	*b_check;
	int		error;
	int		is_running;

	a_check = NULL;
	b_check = NULL;
	error = (parse(argv, argc, &a_check) == 0);
	if (error)
		ft_printf("Error\n");
	is_running = 1;
	while (is_running)
		is_running = handle_ope(ft_get_next_line(0), &a_check, &b_check);
	if (is_sorted(a_check) && ft_lstsize(b_check) == 0)
	{
		ft_printf("OK\n");
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		return (1);
	}
}

//ARG="10 7 8 2 3 6 1 4 9 5"; ./push_swap $ARG | ./CHECKER $ARG

