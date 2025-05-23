/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_edit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:03 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:44:00 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

int	fill_map_line(char **map, char **nmap, int j, int i)
{
	while (map[i][j] != '\0')
	{
		if (map[i][j] == ' ')
			nmap[i][j] = 'x';
		else
			nmap[i][j] = map[i][j];
		j++;
	}
	return (j);
}

int	fill_by_x(char **nmap, int j, int i, int max)
{
	while (j < max)
	{
		nmap[i][j] = 'x';
		j++;
	}
	return (j);
}

char	**replace_spaces(char **map, int max, int rows)
{
	char	**nmap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nmap = malloc(sizeof(char *) * (rows + 1));
	if (!nmap)
		return (NULL);
	while (i < rows)
	{
		j = 0;
		nmap[i] = malloc(sizeof(char) * max + 1);
		if (!nmap[i])
			return (clean_map(nmap), NULL);
		j = fill_map_line(map, nmap, j, i);
		j = fill_by_x(nmap, j, i, max);
		nmap[i][j] = '\0';
		i++;
	}
	nmap[i] = NULL;
	return (nmap);
}

int	get_maxlen(char **map)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (max < len)
			max = len;
		i++;
	}
	return (max);
}
