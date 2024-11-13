/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:32 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:16:32 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (!dest && !src)
		return (dest);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*a = *b;
		i++;
		a++;
		b++;
	}
	return (dest);
}
