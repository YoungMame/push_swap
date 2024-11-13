/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:01 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:16:03 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int i_len)
{
	if (fd < 0)
		return (i_len);
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		i_len += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		i_len = ft_putnbr_fd(n / 10, fd, i_len);
		i_len = ft_putnbr_fd(n % 10, fd, i_len);
	}
	else
		i_len += ft_putchar_fd(n + '0', fd);
	return (i_len);
}
