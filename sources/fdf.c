/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/05 03:10:21 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_data	map;
	t_mlx_data	mlx_data;

	if (argc != 2)
		return (1);
	map.file = argv[1];
	map.mlx_data = &mlx_data;
	init_mlx(&mlx_data);
	clear_image(&mlx_data);
	map_read_and_draw(&map, &mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img, 0, 0);
	setup_hooks_and_loop(&mlx_data);
	cleanup_mlx(&mlx_data);
	return (0);
}
