/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:36:47 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/06/10 14:27:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buffer)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			if (i == 0)
				return (line);
			if (i == -1)
				return (NULL);
			buffer[i] = '\0';
		}
		line = ft_strjoin(line, buffer);
		ft_clean_buf(buffer);
		if (search_nl(line))
			break ;
	}
	return (line);
}

/* int main()
{
	char *line;
	int fd;
	int n = 10;

	fd = open ("file1.txt", O_RDONLY);
	if (fd == -1)
	{
		write (1, "Error opening file\n", 19);
		return (1);
	}
	while (n)
	{
		line = get_next_line (fd);
		printf("%s", line);
		free (line);
		n--;
	}
	close(fd);
	return (0);
} */
