/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:38:29 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:50:53 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"
#define SPEED	0.07f
#define ROTATE 0.07f

bool	is_free_space(char **map, float x, float y)
{
	float	x1;
	float	y1;

	x1 = x + SPEED + 0.5 * SPEED;
	y1 = y + SPEED + 0.5 * SPEED;
	if (map[(int)y1][(int)x1] == '0')
		return (true);
	else
		return (false);
}

void	get_angle(t_game_data **iData, char c)
{
	if (c == 'N')
		(*iData)->angle = 0.5f * PI;
	if (c == 'S')
		(*iData)->angle = -0.5f * PI;
	if (c == 'E')
		(*iData)->angle = 0.0f * PI;
	if (c == 'W')
		(*iData)->angle = 1.0f * PI;
}
