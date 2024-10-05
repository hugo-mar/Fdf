/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:59:26 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/05 02:06:07 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line(t_line *line)
{
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	line->err = line->dx - line->dy;
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
}

void	draw_line(t_line *line, t_mlx_data *data, int color)
{
	int	err2;

	init_line(line);
	while (1)
	{
		my_mlx_pixel_put(data, line->x0, line->y0, color);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		err2 = line->err * 2;
		if (err2 > -line->dy)
		{
			line->err -= line->dy;
			line->x0 += line->sx;
		}
		if (err2 < line->dx)
		{
			line->err += line->dx;
			line->y0 += line->sy;
		}
	}
}

static void	set_and_draw(t_mlx_data *mlx_data, t_point *points, int i1, int i2)
{
	t_line	line;

	line.x0 = points[i1].x;
	line.y0 = points[i1].y;
	line.x1 = points[i2].x;
	line.y1 = points[i2].y;
	draw_line(&line, mlx_data, points[i1].color);
}

void	sketch(t_mlx_data *mlx_data, t_point *points, int width, int height)
{
	int	index;
	int	h;
	int	w;

	h = 0;
	index = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			if (w < width - 1)
				set_and_draw(mlx_data, points, index, index + 1);
			if (h < height - 1)
				set_and_draw(mlx_data, points, index, index + width);
			w++;
			index++;
		}
		h++;
	}
}
