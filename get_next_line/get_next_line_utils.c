/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:34:25 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/01 19:59:28 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_clean_buf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		i++;
		while (buf[i])
			buf[j++] = buf[i++];
		buf[j] = '\0';
	}
	else
		buf[0] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	joint = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joint)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			joint[j++] = s1[i++];
		i = 0;
	}
	while (s2[i] && s2[i] != '\n')
		joint[j++] = s2[i++];
	if (s2[i] == '\n')
		joint[j++] = '\n';
	joint[j] = '\0';
	if (s1)
		free (s1);
	return (joint);
}

int	search_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
