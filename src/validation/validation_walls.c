/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:49:22 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:49:39 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

char	get_last_nonspace(char *line)
{
	if (!line)
		return (line[0]);
	return ('1');
}

bool	has_space_around(char **map, int y, int x)
{
	if (map[y][x])
	{
		if (map[y][x + 1] == 'x')
			return (true);
		else if (map[y][x - 1] == 'x')
			return (true);
		else if (map[y + 1][x] == 'x')
			return (true);
		else if (map[y - 1][x] == 'x')
			return (true);
	}
	return (false);
}

bool	on_eage(int y, int x, int height, int widht)
{
	if (y == 0 || y >= height)
		return (print_message("0 on eage"), true);
	else if (x == 0 || x >= widht)
		return (print_message("0 on eage"), true);
	else
		return (false);
}

bool	check_walls(char **map, int height, int widht)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || is_hero(map[i][j]))
			{
				if (on_eage(i, j, height, widht) || has_space_around(map, i, j))
				{
					printf("check walls return false, line:%s\n", map[i]);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}
