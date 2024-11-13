/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:06 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/23 18:16:08 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (len += ft_putchar_fd('\n', fd));
}
