/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fts2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:35:52 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/05 02:04:10 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_bounds(t_point *points, int count, t_bounds *bounds)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	initialize_bounds(bounds);
	while (index < count)
	{
		x = points[index].x;
		y = points[index].y;
		update_bounds(bounds, x, y);
		index++;
	}
}

void	calculate_and_scale(t_bounds *bounds, t_point *points, int count)
{
	int	figure_width;
	int	figure_height;
	int	multiplier;
	int	index;

	figure_width = bounds->x_max - bounds->x_min;
	figure_height = bounds->y_max - bounds->y_min;
	if (figure_width == 0 || figure_height == 0)
		multiplier = 1;
	else
	{
		multiplier = (WIN_WIDTH - (FRAME * 2)) / figure_width;
		if (((WIN_HEIGHT - (FRAME * 2)) / figure_height) < multiplier)
			multiplier = (WIN_HEIGHT - (FRAME * 2)) / figure_height;
	}
	index = 0;
	while (index < count)
	{
		points[index].x *= multiplier;
		points[index].y *= multiplier;
		points[index].z *= multiplier;
		index++;
	}
}

void	calculate_and_move(t_bounds *bounds, t_point *points, int count)
{
	int	x_distance;
	int	y_distance;
	int	to_move_x;
	int	to_move_y;
	int	index;

	x_distance = bounds->x_max - bounds->x_min;
	y_distance = bounds->y_max - bounds->y_min;
	to_move_x = (WIN_WIDTH / 2) - (x_distance / 2) - bounds->x_min;
	to_move_y = (WIN_HEIGHT / 2) - (y_distance / 2) - bounds->y_min;
	index = 0;
	while (index < count)
	{
		points[index].x += to_move_x;
		points[index].y += to_move_y;
		index++;
	}
}

void	set_points(t_point *points, int width, int height)
{
	t_bounds	bounds;
	int			count;

	count = width * height;
	compute_projected_bounds(points, count, &bounds);
	calculate_and_scale(&bounds, points, count);
	apply_isometric_projection(points, count);
	compute_bounds(points, count, &bounds);
	calculate_and_move(&bounds, points, count);
}
