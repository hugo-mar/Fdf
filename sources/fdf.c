/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:10 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
}

void	setup_hooks_and_loop(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->win, 2, 1L << 0, keyboard_exit, mlx_data);
	mlx_hook(mlx_data->win, 17, 0L, mouse_exit, mlx_data);
	mlx_loop(mlx_data->mlx);
}

void	cleanup_mlx(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
}

int	main(int argc, char **argv)
{
	t_map_data	map;
	t_mlx_data	mlx_data;

	if (argc != 2)
		return (1);
	map.file = argv[1];
	get_map_info(&map);
	init_mlx(&mlx_data);
	clear_image(&mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img, 0, 0);
	setup_hooks_and_loop(&mlx_data);
	cleanup_mlx(&mlx_data);
	return (0);
}
