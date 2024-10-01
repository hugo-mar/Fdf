/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:48:54 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/09/30 16:04:31 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_point_value(char *value_str)
{
	int	value;

	if (!point_validity(value_str))
		handle_error(NULL, NULL, "Invalid point value\n");
	value = ft_atol_base(value_str, 10);
	if (value > INT_MAX || value < INT_MIN)
		handle_error(NULL, NULL, "Invalid point value\n");
	return (value);
}

static int	get_point_color(char *color_str)
{
	int	color;

	color = ft_atol_base(color_str, 16);
	if (color > 16777215 || color < 0)
		handle_error(NULL, NULL, "Invalid point color\n");
	return (color);
}

static void	process_point(t_map_data *map, char *point, int row, int column)
{
	char	**value_and_color;

	value_and_color = ft_split(point, ',');
	if (!value_and_color)
		handle_error(NULL, NULL, "Memory allocation error\n");
	map->data[row][column].value = get_point_value(value_and_color[0]);
	if (value_and_color[1])
		map->data[row][column].color = get_point_color(value_and_color[1]);
	else
		map->data[row][column].color = 16777215;
	ft_free(value_and_color);
}

static void	process_line(t_map_data *map, char *line, int row)
{
	int		column;
	char	**points;

	column = 0;
	line = ft_strtrimtwist(line, " \n");
	if (!line)
		handle_error(NULL, NULL, "Memory allocation error\n");
	points = ft_split(line, ' ');
	if (!points)
	{
		free(line);
		handle_error(NULL, NULL, "Memory allocation error\n");
	}
	free(line);
	while (column < map->width)
	{
		process_point(map, points[column], row, column);
		column++;
	}
	ft_free(points);
}

void	fill_map_data(t_map_data *map, int fd)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		process_line(map, line, row);
		row++;
		if (row > map->height)
		{
			write(1, "Error: Exceeded map height\n", 27);
			exit(1);
		}
		line = get_next_line(fd);
	}
}
