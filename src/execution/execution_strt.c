/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_strt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:37:17 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:50:49 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"

void	get_spawn_posit(t_game_data **iData)
{
	int	x;
	int	y;

	y = 0;
	while ((*iData)->maplines[y])
	{
		x = 0;
		while ((*iData)->maplines[y][x])
		{
			if (is_hero((*iData)->maplines[y][x]))
			{
				(*iData)->sp_y = y + 0.5f;
				(*iData)->sp_x = x + 0.5f;
				get_angle(iData, (*iData)->maplines[y][x]);
			}
			x++;
		}
		y++;
	}
	return ;
}

bool	set_image(t_game_data **iData, t_txtr *texture)
{
	texture->img = mlx_xpm_file_to_image((*iData)->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (print_message("Error:Problem reading texture file"), false);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (true);
}

bool	init_sources(t_game_data **iData)
{
	if (!set_image(iData, &(*iData)->no_path))
		return (false);
	if (!set_image(iData, &(*iData)->so_path))
		return (false);
	if (!set_image(iData, &(*iData)->we_path))
		return (false);
	if (!set_image(iData, &(*iData)->ea_path))
		return (false);
	return (true);
}

int	destroy_prog(t_game_data *iData)
{
	if (iData->win_ptr)
		mlx_destroy_window(iData->mlx, iData->win_ptr);
	mlx_destroy_image(iData->mlx, iData->no_path.img);
	mlx_destroy_image(iData->mlx, iData->so_path.img);
	mlx_destroy_image(iData->mlx, iData->we_path.img);
	mlx_destroy_image(iData->mlx, iData->ea_path.img);
	exit_program("Exiting program from ESC\n", iData);
	exit (1);
}

bool	execute(t_game_data **iData)
{
	get_spawn_posit(iData);
	(*iData)->mlx = mlx_init();
	if (!init_sources(iData))
		return (print_message("Error:Failed processing sources"), false);
	(*iData)->win_ptr = mlx_new_window((*iData)->mlx, WINDOW_W, WINDOW_H,
			"Cube_3D");
	draw_map(iData);
	mlx_hook((*iData)->win_ptr, 2, 0, key_hook, iData);
	mlx_hook((*iData)->win_ptr, 17, 0, &destroy_prog, *iData);
	mlx_loop((*iData)->mlx);
	return (true);
}
