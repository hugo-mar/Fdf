/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/06 01:47:43 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FRAME 20
# define P_ANGLE 0.5235987755982989
# define ESC_KEY 65307

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>	
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

typedef struct s_map_data
{
	char		*file;
	int			width;
	int			height;
	int			current_row;
	int			current_index;
	t_point		*points;
	t_mlx_data	*mlx_data;
}			t_map_data;

typedef struct s_bounds
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}			t_bounds;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}			t_line;

void	ft_free(char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strtrimtwist(char *s1, char const *set, t_map_data *map);
long	ft_atol_base(const char *nptr, int base);

void	map_read_and_draw(t_map_data *map, t_mlx_data *mlx_data);
void	get_map_size(t_map_data *map);
void	free_map_data(t_map_data *map);
void	fill_map_data(t_map_data *map, int fd);
void	handle_error(t_map_data *data, char **points, char **value_and_color,
			const char *msg);
void	map_check_and_free(t_map_data *data, int wd, char *line, char **points);
bool	point_validity(char *point);

void	init_mlx(t_mlx_data *mlx_data);
void	setup_hooks_and_loop(t_mlx_data *mlx_data);
void	cleanup_mlx(t_mlx_data *mlx_data);
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void	clear_image(t_mlx_data *data);
void	draw_line(t_line *line, t_mlx_data *data, int color);
void	sketch(t_mlx_data *mlx_data, t_point *points, int width, int height);

void	apply_isometric_projection(t_point *points, int count);
void	initialize_bounds(t_bounds *bounds);
void	update_bounds(t_bounds *bounds, int x, int y);
void	compute_bounds(t_point *points, int count, t_bounds *bounds);
void	compute_projected_bounds(t_point *points, int count, t_bounds *bounds);
void	calculate_and_scale(t_bounds *bounds, t_point *points, int count);
void	calculate_and_move(t_bounds *bounds, t_point *points, int count);
void	set_points(t_point *points, int width, int height);

#endif