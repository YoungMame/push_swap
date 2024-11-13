/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:50 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/24 17:25:06 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	in_word;
	int	got_sep;
	int	total;

	i = 0;
	in_word = 0;
	total = 0;
	while (str[i])
	{
		got_sep = (str[i] == c);
		if (got_sep)
			in_word = 0;
		if ((!got_sep) && (!in_word))
		{
			in_word = 1;
			total++;
		}
		i++;
	}
	return (total);
}

static char	*ft_dup(const char *str, int min, int max)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (max - min + 2));
	if (!dest)
		return (NULL);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (min <= max)
		dest[i++] = str[min++];
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		min;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	min = -1;
	while (s[i])
	{
		if (!(s[i] == c) && min == -1)
			min = i;
		if ((s[i + 1] == c || s[i + 1] == '\0') && min != -1)
		{
			result[j++] = ft_dup(s, min, i);
			min = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}

// int	main()
// {
// 	int	i;
// 	char **result = ft_split("caca", "c");
// 	//printf("%d\n", ft_is_sep('c', ""));

// 	i = 0;
// 	while (result[i])
// 		printf(" : %s\n", result[i++]);
// 	return (1);
// }