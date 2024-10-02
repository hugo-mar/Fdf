/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/02 01:53:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>	
# include <stdbool.h>
# include <limits.h>

# include "get_next_line/get_next_line.h"

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
}			t_map_data;

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

#endif