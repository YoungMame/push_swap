/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:50:13 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/22 16:51:59 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_get_digits_count(int n)
{
	int	result;

	result = 1;
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits_count;
	char	*str;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = (n < 0);
	digits_count = ft_get_digits_count(n);
	str = malloc(sizeof(char) * (digits_count + 1 + is_negative));
	if (str == NULL)
		return (NULL);
	if (is_negative)
	{
		str[0] = '-';
		n = -n;
	}
	str[digits_count + is_negative] = '\0';
	while (digits_count > 0)
	{
		digits_count--;
		str[digits_count + is_negative] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
