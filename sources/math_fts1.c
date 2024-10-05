/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fts1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:11 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/05 02:03:28 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso_projection(int *x, int *y, int z)
{
	int	x_proj;
	int	y_proj;

	x_proj = (int)round((*x) * cos(P_ANGLE) - (*y) * cos(P_ANGLE));
	y_proj = (int)round((*x) * sin(P_ANGLE) + (*y) * sin(P_ANGLE) - z);
	*x = x_proj;
	*y = y_proj;
}

void	apply_isometric_projection(t_point *points, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		iso_projection(&points[index].x, &points[index].y, points[index].z);
		index++;
	}
}

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
