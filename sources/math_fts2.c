/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fts2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:35:52 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/07 00:31:37 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric_projection(t_point *points, int count)
{
	int	index;
	int	projected_x;
	int	projected_y;

	index = 0;
	while (index < count)
	{
		projected_x = (int)round(points[index].x * cos(P_ANGLE)
				- points[index].y * cos(P_ANGLE));
		projected_y = (int)round(points[index].x * sin(P_ANGLE)
				+ points[index].y * sin(P_ANGLE) - points[index].z);
		points[index].x = projected_x;
		points[index].y = projected_y;
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
	int	figure_width;
	int	figure_height;
	int	to_move_x;
	int	to_move_y;
	int	index;

	figure_width = bounds->x_max - bounds->x_min;
	figure_height = bounds->y_max - bounds->y_min;
	to_move_x = (WIN_WIDTH / 2) - (figure_width / 2) - bounds->x_min;
	to_move_y = (WIN_HEIGHT / 2) - (figure_height / 2) - bounds->y_min;
	index = 0;
	while (index < count)
	{
		points[index].x += to_move_x;
		points[index].y += to_move_y;
		index++;
	}
}
