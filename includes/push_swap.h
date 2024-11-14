/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:27 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/07 18:56:26 by mduvey           ###   ########.fr       */
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
# include "../libft/libft.h"


void		do_sa(t_list **a, t_list **b);
void		do_sa(t_list **a, t_list **b);
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
int			get_rotation_way(t_list *target, t_list *list);
t_list		*get_biggest(t_list *list);
t_list		*get_smaller(t_list *list, int target);
int			get_reverse_rotation_cost(t_list *target, t_list *list);
int			get_rotation_cost(t_list *target, t_list *list);
void		free_stack_content(void *content);

#endif