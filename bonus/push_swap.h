/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:27 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/21 16:27:45 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <aio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_move
{
	t_list	*source;
	t_list	*target;
	int		cost;
}	t_move;

void		do_sa(t_list **a);
void		do_sb(t_list **b);
void		do_ss(t_list **a, t_list **b);
void		do_pa(t_list **a, t_list **b);
void		do_pb(t_list **a, t_list **b);
void		do_ra(t_list **a);
void		do_rb(t_list **b);
void		do_rr(t_list **a, t_list **b);
void		do_rra(t_list **a);
void		do_rrb(t_list **b);
void		do_rrr(t_list **a, t_list **b);
int			get_content_value(t_list *list);
void		free_stack_content(void *content);
int			parse(char **args, int argc, t_list **a);
int			is_sorted(t_list *list);

#endif