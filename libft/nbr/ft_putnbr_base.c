/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:08:24 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/30 15:20:47 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	a;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] > 126 || base[i] == ' ')
			return (0);
		a = i + 1;
		while (base[a])
		{
			if (base[a] == base[i])
				return (0);
			a++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base, int i_len)
{
	int		base_l;
	long	num;

	base_l = ft_strlen(base);
	if (!check_base(base))
		return (i_len);
	num = nbr;
	if (num < 0)
	{
		num = -num;
		i_len += ft_putchar('-');
	}
	if (num >= 0)
	{
		if (num / base_l > 0)
			i_len = ft_putnbr_base(num / base_l, base, i_len);
		i_len += ft_putchar(base[num % base_l]);
	}
	return (i_len);
}

int	ft_putnbr_base_unsigned(unsigned long long nbr, char *base, int i_len)
{
	int						base_l;
	unsigned long long int	num;

	base_l = ft_strlen(base);
	if (!check_base(base))
		return (i_len);
	num = nbr;
	if (num / base_l > 0)
		i_len = ft_putnbr_base_unsigned(num / base_l, base, i_len);
	i_len += ft_putchar(base[num % base_l]);
	return (i_len);
}
