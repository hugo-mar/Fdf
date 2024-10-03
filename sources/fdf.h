/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/03 13:51:45 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ESC_KEY 65307

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>	
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"

# include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

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

typedef struct s_map_data
{
	char		*file;
	int			width;
	int			height;
	int			current_row;
	int			current_index;
	t_point		*points;
}			t_map_data;

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

void	ft_free(char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strtrimtwist(char *s1, char const *set);
long	ft_atol_base(const char *nptr, int base);

void	get_map_size(t_map_data *map);
void	free_map_points(t_map_data *map);
void	get_map_info(t_map_data *map);

void	fill_map_data(t_map_data *map, int fd);

void	handle_error(char **points, char **value_and_color, const char *msg);
void	map_check_and_free(t_map_data *data, int wd, char *line, char **points);
bool	point_validity(char *point);

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void	clear_image(t_mlx_data *data);
int		keyboard_exit(int keycode, t_mlx_data *data);
int		mouse_exit(t_mlx_data *data);
void	draw_line(t_line *line, t_mlx_data *data, int color);

#endif