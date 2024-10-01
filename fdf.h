/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/01 19:52:54 by hugo-mar         ###   ########.fr       */
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

typedef struct s_point_data
{
	int	value;
	int	color;
}			t_point_data;

typedef struct s_map_data
{
	char			*file;
	int				width;
	int				height;
	t_point_data	**data;
}			t_map_data;

void	ft_free(char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strtrimtwist(char *s1, char const *set);
long	ft_atol_base(const char *nptr, int base);

bool	point_validity(char *point);
void	map_check_and_free(t_map_data *data, int wd, char *line, char **points);
void	get_map_size(t_map_data *map);
bool	allocate_map(t_map_data *map);
void	free_map(t_map_data *map);
void	handle_error(char **points, char **value_and_color, const char *msg);

void	fill_map_data(t_map_data *map, int fd);
void	get_map_info(t_map_data *data);

#endif