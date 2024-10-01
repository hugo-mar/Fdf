/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/09/30 17:17:40 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map_data *map)
{
	int	i;

	if (map)
	{
		if (map->data)
		{
			i = 0;
			while (i < map->height)
			{
				if (map->data[i])
				{
					free(map->data[i]);
					map->data[i] = NULL;
				}
				i++;
			}
			free(map->data);
			map->data = NULL;
		}
	}
}

bool	allocate_map(t_map_data *map)
{
	int	i;

	map->data = malloc(sizeof(t_point_data *) * map->height);
	if (!map->data)
		return (false);
	i = 0;
	while (i < map->height)
	{
		map->data[i] = malloc(sizeof(t_point_data) * map->width);
		if (!map->data[i])
		{
			free_map(map);
			return (false);
		}
		i++;
	}
	return (true);
}

void	handle_error(char **points, char **value_and_color, const char *msg)
{
	if (points)
		ft_free(points);
	if (value_and_color)
		ft_free(value_and_color);
	write(1, msg, ft_strlen(msg));
	exit(1);
}

void	map_check_and_free(t_map_data *data, int wd, char *line, char **points)
{
	if (wd != data->width)
	{
		free(line);
		handle_error(points, NULL, "Invalid map\n");
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
