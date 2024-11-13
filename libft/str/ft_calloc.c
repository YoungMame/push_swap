/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:18:05 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:18:05 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	s;
	char			*ptr;

	s = nmemb * size;
	ptr = malloc(s);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, s);
	return (ptr);
}
