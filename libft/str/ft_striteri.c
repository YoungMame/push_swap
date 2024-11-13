/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:31 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:15:33 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		length;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}
