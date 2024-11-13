/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:16:18 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/30 18:04:15 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_x(unsigned int u)
{
	int	str_len;

	str_len = 0;
	str_len += ft_putnbr_base_unsigned(u, "0123456789abcdef", 0);
	return (str_len);
}

int	print_x_upper(unsigned int u)
{
	int	str_len;

	str_len = 0;
	str_len += ft_putnbr_base_unsigned(u, "0123456789ABCDEF", 0);
	return (str_len);
}

int	print_o(unsigned int u)
{
	int	str_len;

	str_len = 0;
	str_len += ft_putnbr_base_unsigned(u, "01234567", 0);
	return (str_len);
}
