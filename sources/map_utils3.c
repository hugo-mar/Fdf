/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/07 12:53:57 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(t_map_data *data, char **points, char **value_and_color,
			const char *msg)
{
	cleanup_mlx(data->mlx_data);
	if (points)
		ft_free(points);
	if (value_and_color)
		ft_free(value_and_color);
	if (write(1, msg, ft_strlen(msg)) == -1)
		perror("write");
	exit(1);
}

void	map_check_and_free(t_map_data *data, int wd, char *line, char **points)
{
	if (wd != data->width)
	{
		free(line);
		handle_error(data, points, NULL, "Invalid map\n");
	}
	ft_free(points);
	free(line);
}

bool	point_validity(char *point)
{
	if (point == NULL || *point == '\0')
		return (false);
	if (*point == '+' || *point == '-')
		point++;
	if (!*point)
		return (false);
	while (*point)
	{
		if (*point < '0' || *point > '9')
			return (false);
		point++;
	}
	return (true);
}

void	check_empty_map(char *file)
{
	int		fd;
	char	buffer[50];
	int		bytes_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror ("Error opening file");
		exit(1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror ("Error reading file");
		close (fd);
		exit(1);
	}
	if (bytes_read == 0)
	{
		close (fd);
		exit(0);
	}
	close (fd);
}
