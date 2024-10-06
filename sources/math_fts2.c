/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fts2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:35:52 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/06 17:23:32 by hugo-mar         ###   ########.fr       */
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
