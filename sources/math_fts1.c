/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fts1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/06 17:22:53 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_bounds(t_bounds *bounds)
{
	bounds->x_min = INT_MAX;
	bounds->x_max = INT_MIN;
	bounds->y_min = INT_MAX;
	bounds->y_max = INT_MIN;
}

void	update_bounds(t_bounds *bounds, int x, int y)
{
	if (x < bounds->x_min)
		bounds->x_min = x;
	if (x > bounds->x_max)
		bounds->x_max = x;
	if (y < bounds->y_min)
		bounds->y_min = y;
	if (y > bounds->y_max)
		bounds->y_max = y;
}

void	compute_projected_bounds(t_point *points, int count, t_bounds *bounds)
{
	int	index;
	int	x_proj;
	int	y_proj;

	index = 0;
	initialize_bounds(bounds);
	while (index < count)
	{
		x_proj = (int)round(points[index].x * cos(P_ANGLE)
				- points[index].y * cos(P_ANGLE));
		y_proj = (int)round(points[index].x * sin(P_ANGLE)
				+ points[index].y * sin(P_ANGLE) - points[index].z);
		update_bounds(bounds, x_proj, y_proj);
		index++;
	}
}

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
