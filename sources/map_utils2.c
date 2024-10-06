/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:48:54 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/06 01:48:42 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_point_value(t_map_data *map, char *value_str)
{
	int	value;

	if (!point_validity(value_str))
		handle_error(map, NULL, NULL, "Invalid point value\n");
	value = ft_atol_base(value_str, 10);
	if (value > INT_MAX || value < INT_MIN)
		handle_error(map, NULL, NULL, "Invalid point value\n");
	return (value);
}

static int	get_point_color(t_map_data *map, char *color_str)
{
	int	color;

	color = ft_atol_base(color_str, 16);
	if (color > 16777215 || color < 0)
		handle_error(map, NULL, NULL, "Invalid point color\n");
	return (color);
}

static void	process_point(t_map_data *map, char *point, int column)
{
	char	**z_and_color;

	z_and_color = ft_split(point, ',');
	if (!z_and_color)
		handle_error(map, NULL, NULL, "Memory allocation error\n");
	map->points[map->current_index].x = column;
	map->points[map->current_index].y = map->current_row;
	map->points[map->current_index].z = get_point_value(map, z_and_color[0]);
	if (z_and_color[1])
		map->points[map->current_index].color
			= get_point_color(map, z_and_color[1]);
	else
		map->points[map->current_index].color = 16777215;
	map->current_index++;
	ft_free(z_and_color);
}

static void	process_line(t_map_data *map, char *line)
{
	int		column;
	char	**points;

	column = 0;
	line = ft_strtrimtwist(line, " \n", map);
	if (!line)
		handle_error(map, NULL, NULL, "Memory allocation error\n");
	points = ft_split(line, ' ');
	if (!points)
	{
		free(line);
		handle_error(map, NULL, NULL, "Memory allocation error\n");
	}
	free(line);
	while (column < map->width)
	{
		process_point(map, points[column], column);
		column++;
	}
	map->current_row++;
	ft_free(points);
}

void	fill_map_data(t_map_data *map, int fd)
{
	char	*line;

	map->current_index = 0;
	map->current_row = 0;
	map->points = malloc(map->width * map->height * sizeof(t_point));
	if (!map->points)
		handle_error(map, NULL, NULL, "Memory allocation error\n");
	line = get_next_line(fd);
	while (line)
	{
		process_line(map, line);
		if (map->current_row > map->height)
		{
			free(line);
			handle_error(map, NULL, NULL, "Error: Exceeded map height\n");
		}
		line = get_next_line(fd);
	}
}
