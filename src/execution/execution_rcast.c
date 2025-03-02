/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_rcast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:36:43 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:41:16 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"

static float	save_colour(t_game_data *data, float d, int c, float w)
{
	if (c == 0)
		data->cur_txt = data->ea_path;
	if (c == 1)
		data->cur_txt = data->so_path;
	if (c == 2)
		data->cur_txt = data->we_path;
	if (c == 3)
		data->cur_txt = data->no_path;
	data->txt_w = w;
	return (d);
}

void	init_ray(t_game_data *data, t_ray *ray, float v)
{
	ray->delta.x = cos(v);
	ray->delta.y = -sin(v);
	ray->sx = get_isign(ray->delta.x);
	ray->sy = get_isign(ray->delta.y);
	ray->vertic.x = (int) data->sp_x;
	if (ray->sx > 0)
		ray->vertic.x = ray->vertic.x + 1.0f;
	ray->horiz.y = (int) data->sp_y;
	if (ray->sy > 0)
		ray->horiz.y = ray->horiz.y + 1.0f;
	ray->vertic.y = 0;
	ray->horiz.x = 0;
	ray->vert_w = 0;
	ray->hor_w = 0;
}

void	set_vert_horiz_dist(t_game_data *data, t_ray *ray)
{
	if (ray->sx != 0)
	{
		ray->vertic.y = data->sp_y + ray->delta.y / ray->delta.x
			* (ray->vertic.x - data->sp_x);
		ray->vdist = sqrt(pow(data->sp_x - ray->vertic.x, 2.0)
				+ pow(data->sp_y - ray->vertic.y, 2.0));
		ray->vert_w = ray->vertic.y - (int)ray->vertic.y;
		if (ray->sx > 0)
			ray->vert_w = 1 - ray->vert_w;
	}
	else
		ray->vdist = INFINITY;
	if (ray->sy != 0)
	{
		ray->horiz.x = data->sp_x + ray->delta.x / ray->delta.y
			* (ray->horiz.y - data->sp_y);
		ray->hdist = sqrt(pow(data->sp_x - ray->horiz.x, 2.0)
				+ pow(data->sp_y - ray->horiz.y, 2.0));
		ray->hor_w = ray->horiz.x - (int)ray->horiz.x;
		if (ray->sy < 0)
			ray->hor_w = 1 - ray->hor_w;
	}
	else
		ray->hdist = INFINITY;
}

float	set_ray(t_game_data *data, float v)
{
	t_ray	new_ray;

	init_ray(data, &new_ray, v);
	while (1)
	{
		set_vert_horiz_dist(data, &new_ray);
		if (new_ray.vdist < new_ray.hdist)
		{
			if (iswall(data->maplines[(int)new_ray.vertic.y]
					[(int)new_ray.vertic.x + (new_ray.sx - 1) / 2]))
				return (save_colour(data, new_ray.vdist, new_ray.sx + 1,
						new_ray.vert_w));
			else
				new_ray.vertic.x = new_ray.vertic.x + new_ray.sx;
		}
		else
		{
			if (iswall(data->maplines[(int)new_ray.horiz.y + (new_ray.sy - 1)
						/ 2][(int)new_ray.horiz.x]))
				return (save_colour(data, new_ray.hdist, new_ray.sy + 2,
						new_ray.hor_w));
			else
				new_ray.horiz.y = new_ray.horiz.y + new_ray.sy;
		}
	}
}

bool	raycasting(t_game_data **idata)
{
	float	dv;
	float	v;
	int		x;

	v = (*idata)->angle + FOV / 2;
	dv = FOV / (WINDOW_W - 1);
	x = -1;
	while (++x < WINDOW_W)
	{
		set_line((*idata), x, set_ray((*idata), v) * cos((*idata)->angle - v));
		v = v - dv;
	}
	return (true);
}
