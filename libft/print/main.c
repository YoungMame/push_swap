/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:12:10 by MelanieBout       #+#    #+#             */
/*   Updated: 2024/10/30 17:16:03 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	manage_conversion(char c, va_list valist)
{
	int	str_len;

	str_len = 0;
	if (c == 'c')
		str_len += print_c(va_arg(valist, int));
	else if (c == 's')
		str_len += print_s(va_arg(valist, char *));
	else if (c == 'd' || c == 'i')
		str_len += print_i(va_arg(valist, int));
	else if (c == 'u')
		str_len += print_u(va_arg(valist, unsigned int));
	else if (c == 'x')
		str_len += print_x(va_arg(valist, unsigned int));
	else if (c == 'X')
		str_len += print_x_upper(va_arg(valist, unsigned int));
	else if (c == 'o')
		str_len += print_o(va_arg(valist, unsigned int));
	else if (c == 'p')
		str_len += print_p(va_arg(valist, void *));
	else
		str_len += ft_putchar(c);
	return (str_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		str_len;
	va_list	valist;

	if (!format)
		return (0);
	va_start(valist, format);
	str_len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			str_len += manage_conversion(format[i + 1], valist);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			str_len++;
		}
		i++;
	}
	return (str_len);
}
