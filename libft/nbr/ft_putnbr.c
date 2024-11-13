/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:01 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/29 11:54:53 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int i_len)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		i_len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		i_len = ft_putnbr(n / 10, i_len);
		i_len = ft_putnbr(n % 10, i_len);
	}
	else
		i_len += ft_putchar(n + '0');
	return (i_len);
}

int	ft_putnbr_unsigned(unsigned int n, int i_len)
{
	if (n >= 10)
	{
		i_len = ft_putnbr(n / 10, i_len);
		i_len = ft_putnbr(n % 10, i_len);
	}
	else
		i_len += ft_putchar(n + '0');
	return (i_len);
}
