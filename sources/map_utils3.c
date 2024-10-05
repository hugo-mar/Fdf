/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/05 03:13:38 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(char **points, char **value_and_color, const char *msg)
{
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
		cleanup_mlx(data->mlx_data);
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
