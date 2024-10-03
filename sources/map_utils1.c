/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:44:23 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/02 02:25:34 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	open_map_file(t_map_data *map, int *fd)
{
	*fd = open(map->file, O_RDONLY);
	if (*fd == -1)
		handle_error(NULL, NULL, "Error opening file\n");
}

void	get_map_size(t_map_data *map)
{
	int		fd;
	int		height;
	int		width;
	char	*line;
	char	**points;

	height = 0;
	open_map_file(map, &fd);
	line = get_next_line(fd);
	while (line)
	{
		width = 0;
		line = ft_strtrimtwist(line, " \n");
		points = ft_split(line, ' ');
		while (points[width])
			width++;
		if (height == 0)
			map->width = width;
		map_check_and_free(map, width, line, points);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	map->height = height;
}

void	free_map_data(t_map_data *map)
{
	if (map->points)
	{
		free(map->points);
		map->points = NULL;
	}
}

void	get_map_info(t_map_data *map)
{
	int	fd;

	open_map_file(map, &fd);
	get_map_size(map);
	fill_map_data(map, fd);
	free_map_data(map);
	close(fd);
}
