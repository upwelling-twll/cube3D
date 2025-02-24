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

bool	good_pos(char **map)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (flag < 1)
	{
		x = 0;
		while (map[y][x] && flag < 1)
		{
			if (is_hero(map[y][x]))
			{
				flag = 1;
				break ;
			}
			x++;
		}
		y++;
	}
	if (map[y][x + 1] == '\0' || map[y][x + 1] == '\n' || map[y][x + 1] == '\t')
		return (print_message("Error:Player on edge"), false);
	return (true);
}
