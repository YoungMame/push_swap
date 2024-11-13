/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:22:26 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/30 15:39:08 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr)
{
	size_t	len;
	int		is_negative;

	if (!nbr)
		return (1);
	len = 0;
	is_negative = (nbr < 0);
	if (is_negative)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len + is_negative);
}
