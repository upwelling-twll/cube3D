/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:37:49 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:39:14 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"
#define SPEED	0.07f
#define ROTATE 0.07f

void	changed_position(t_game_data *data, float x, float y)
{
	if (is_free_space(data->maplines, data->sp_x, y))
		data->sp_x = x;
	if (is_free_space(data->maplines, x, data->sp_y))
		data->sp_y = y;
	draw_map(&data);
}

void	updating(t_game_data *data, float *x, float *y, float angle)
{
	float	speed;

	speed = SPEED;
	(*x) += speed * cosf(data->angle + angle);
	(*y) += speed * sinf(data->angle + angle);
}

void	move(t_game_data **data, int direc)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = (*data)->angle + direc * M_PI / 2;
	dx = 0.05f * cos(angle);
	dy = 0.05f * sin(angle);
	dist = set_ray(*data, get_isign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = set_ray(*data, (1 - (get_isign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = set_ray(*data, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (get_isign(dy) * get_isign(dx) != 0)
			dy = 0.0f;
	(*data)->sp_x += dx;
	(*data)->sp_y -= dy;
	draw_map(data);
}

int	key_hook(int keycode, t_game_data **data)
{
	if (keycode == ESC)
		destroy_prog(*data);
	if (keycode == W)
		move(data, 0);
	if (keycode == S)
		move(data, 2);
	if (keycode == A)
		move(data, 3);
	if (keycode == D)
		move(data, 1);
	if (keycode == LEFT)
		rotate(LEFT, *data);
	if (keycode == RIGHT)
		rotate(RIGHT, *data);
	return (0);
}

int	rotate(int keycode, t_game_data *data)
{
	if (keycode == RIGHT)
		data->angle += ROTATE;
	if (keycode == LEFT)
		data->angle -= ROTATE;
	if (data->angle < 0)
		data->angle += 2.f * M_PI;
	if (data->angle > 2.f * M_PI)
		data->angle -= 2.f * M_PI;
	draw_map(&data);
	return (0);
}
