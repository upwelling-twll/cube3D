/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:48:27 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:48:28 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

bool	safe_pos(char **map, int x, int y, int ly)
{
	if (y == ly)
		return (false);
	if (!map[y][x + 1])
		return (false);
	if (map[y][x + 1])
		if (map[y][x + 1] == '\0' || map[y][x + 1] == '\n' \
			 || map[y][x + 1] == '\t')
		return (false);
	if (map[y + 1][x] == '\0' || map[y + 1][x] == '\n' \
		 || map[y + 1][x] == '\t')
		return (false);
	return (true);
}

bool	good_pos(char **map)
{
	int	x;
	int	y;
	int	ly;

	x = 0;
	y = 0;
	ly = -1;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && ly < 0)
		{
			if (is_hero(map[y][x]))
			{
				ly = y;
				break ;
			}
			x++;
		}
		y++;
	}
	if (!safe_pos(map, x, ly, y - 1))
		return (print_message("Error:Player on edge"), false);
	return (true);
}
