/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/09/27 19:47:43 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_point_data
{
	int	value;
	int	color;
}			t_point_data;

typedef struct s_map_data
{
	t_point_data	**data;
	int				width;
	int				height;
}			s_map_data;


void	ft_free(char **argv);
char	**ft_split(char const *s, char c);

void	get_map_info(char *file);

#endif