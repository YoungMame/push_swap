/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:29:04 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/29 13:12:24 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_p(void *ptr)
{
	unsigned long long		ptr_adress;
	int						str_len;

	ptr_adress = (unsigned long long)ptr;
	str_len = 0;
	if (ptr_adress == 0)
		return (ft_putstr("(nil)"));
	str_len += ft_putstr("0x");
	str_len += ft_putnbr_base_unsigned(ptr_adress, "0123456789abcdef", 0);
	return (str_len);
}
