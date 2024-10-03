/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twistft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:05:13 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/10/02 01:24:19 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pre_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	test;

	i = 0;
	j = 0;
	test = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] != set[j])
				test++;
			j++;
		}
		if (test == j)
			return (i);
		i++;
		j = 0;
		test = 0;
	}
	return (0);
}

static int	suf_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	test;

	i = ft_strlen(s1);
	j = 0;
	test = 0;
	while (i >= 0)
	{
		while (set[j])
		{
			if (s1[i - 1] != set[j])
				test++;
			j++;
		}
		if (test == j)
			return (ft_strlen(s1) - i);
		i--;
		j = 0;
		test = 0;
	}
	return (0);
}

char	*ft_strtrimtwist(char *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - pre_len(s1, set) - suf_len(s1, set);
	trimmed = (char *) malloc (sizeof(char) * (len + 1));
	if (!trimmed)
		handle_error(NULL, NULL, "Memory allocation error\n");
	while (i < len)
	{
		trimmed[i] = s1[pre_len(s1, set) + i];
		i++;
	}
	trimmed[i] = '\0';
	free(s1);
	return (trimmed);
}

static int	get_digit_value(char c, int base)
{
	int	digit;

	if (c >= '0' && c <= '9')
		digit = c - '0';
	else if (c >= 'A' && c <= 'Z')
		digit = c - 'A' + 10;
	else if (c >= 'a' && c <= 'z')
		digit = c - 'a' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	return (digit);
}

long	ft_atol_base(const char *nptr, int base)
{
	long	nbr;
	short	parity;
	int		digit;

	nbr = 0;
	parity = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			parity = -1;
		nptr++;
	}
	if (base == 16 && nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X'))
		nptr += 2;
	while (*nptr)
	{
		digit = get_digit_value(*nptr, base);
		if (digit == -1)
			break ;
		nbr = nbr * base + digit;
		nptr++;
	}
	return (nbr * parity);
}
