/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MelanieBouteiller <MelanieBouteiller@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:43 by mduvey            #+#    #+#             */
/*   Updated: 2024/10/27 16:51:44 by MelanieBout      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(char *backup, int j)
{
	int		i;

	i = 0;
	while (backup[j])
		backup[i++] = backup[j++];
	backup[i] = '\0';
}

static char	*next_line(char *backup)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!backup || backup[0] == '\0')
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (backup[j] && backup[j] != '\n')
	{
		line[j] = backup[j];
		j++;
	}
	if (backup[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	fill_buffer(backup, j);
	return (line);
}

static char	*read_file(int fd, char *backup)
{
	int		bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_gnl_strchr(backup, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1 || !buf)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[bytes] = '\0';
		backup = ft_gnl_str_free_join(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*ft_get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = read_file(fd, backup);
	if (!backup)
		return (free(backup), NULL);
	line = next_line(backup);
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*new_line;
// 	char	file_path[] = "read_error.txt";

// 	printf("Test de %s avec la BUFFER_SIZE %i\n", file_path, BUFFER_SIZE);
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 1)
// 		return (0);
// 	new_line = get_next_line(fd);
// 	while (new_line)
// 	{
// 		printf("%s", new_line);
// 		free(new_line);
// 		new_line = get_next_line(fd);
// 		close(fd);
// 	}
// 	printf("\nwe printed all lines\n");
// 	free(new_line);
// 	close(fd);
// 	return (0);
// }
