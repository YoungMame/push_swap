/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:22 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:15:22 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;
	size_t	dst_l;

	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	i = 0;
	if (dst_l + 1 > dstsize)
		return (dstsize + src_l);
	while (src[i] && (dst_l + i) < dstsize - 1)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (src_l + dst_l);
}
