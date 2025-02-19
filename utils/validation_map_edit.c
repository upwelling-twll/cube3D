/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_edit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:03 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:33:12 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

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
	printf("rows:%i\n", rows);
	while (i < rows)
	{
		j = 0;
		nmap[i] = malloc(sizeof(char) * max + 1);
		if (!nmap[i])
			return (clean_map(nmap), NULL);
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ')
				nmap[i][j] = 'x';
			else
				nmap[i][j] = map[i][j];
			j++;
		}
		while (j < max)
		{
			nmap[i][j] = 'x';
			j++;
		}
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

bool	is_comma(char c)
{
	if (c == ',')
		return (true);
	else
		return (false);
}

char	*skip_comma(char *line)
{
	if (!(is_end_of_line(*line)))
	{
		line++;
	}
	return (line);
}
