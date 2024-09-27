/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/09/27 19:40:21 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)		//Subject to change
		return (1);
	int	 fd;
	char *line;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);	
	while ((line = get_next_line(fd)))
	{
		printf("%s",line);
		free(line);
	}
	return (0);
}