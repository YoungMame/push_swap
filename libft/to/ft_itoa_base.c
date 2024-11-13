/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:35:55 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/30 18:01:01 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base)
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

static int	ft_get_digits_count(unsigned long long n, int base_l)
{
	int	result;

	result = 1;
	while (n / base_l > 0)
	{
		n /= base_l;
		result++;
	}
	return (result);
}

static void	ft_handle_sign(long *num, int is_negative, char *str)
{
	if (is_negative)
	{
		str[0] = '-';
		*num = -(*num);
	}
}

char	*ft_itoa_base(int n, char *base)
{
	long	num;
	int		base_l;
	int		digits_count;
	int		is_negative;
	char	*str;

	if (!ft_check_base(base))
		return ("\0");
	num = n;
	base_l = ft_strlen(base);
	digits_count = ft_get_digits_count(num, base_l);
	is_negative = (num < 0);
	str = malloc(sizeof(char) * (digits_count + 1 + is_negative));
	if (str == NULL)
		return (NULL);
	str[digits_count + is_negative] = '\0';
	ft_handle_sign(&num, is_negative, str);
	while (digits_count > 0)
	{
		digits_count--;
		str[digits_count + is_negative] = base[num % base_l];
		num /= base_l;
	}
	return (str);
}

char	*ft_itoa_base_unsigned(unsigned long long n, char *base)
{
	int				base_l;
	int				digits_count;
	char			*str;

	if (!ft_check_base(base))
		return ("\0");
	base_l = ft_strlen(base);
	digits_count = ft_get_digits_count(n, base_l);
	str = malloc(sizeof(char) * (digits_count + 1));
	if (str == NULL)
		return (NULL);
	str[digits_count] = '\0';
	while (digits_count > 0)
	{
		digits_count--;
		str[digits_count] = base[n % base_l];
		n /= base_l;
	}
	return (str);
}
