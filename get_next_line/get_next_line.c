/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:42:45 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/27 19:31:20 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i == 0)
				return (result);
			if (i == -1)
				return (NULL);
			buf[i] = '\0';
		}
		result = ft_strjoin(result, buf);
		if (chrnline(result))
			break ;
	}
	return (result);
}
