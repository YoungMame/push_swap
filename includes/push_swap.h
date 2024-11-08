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

# include <aio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		do_sa(t_list **a, t_list **b);
int		do_sa(t_list **a, t_list **b);
int		do_ss(t_list **a, t_list **b);
int		do_pa(t_list **a, t_list **b);
int		do_pb(t_list **a, t_list **b);
int		do_ra(t_list **a);
int		do_rb(t_list **b);
int		do_rr(t_list **a, t_list **b);
int		do_rra(t_list **a);
int		do_rrb(t_list **b);
int		do_rrr(t_list **a, t_list **b);


#endif