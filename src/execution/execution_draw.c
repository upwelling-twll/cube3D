/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:36:02 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:36:36 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"

void	rgb_to_hex(t_rgb *text)
{
	text->hcolour = (text->red << 16) | (text->green << 8) | text->blue;
}

void	draw_interior(t_game_data **idata)
{
	unsigned int	*iaddr;
	unsigned int	npxl;

	iaddr = (unsigned int *)(*idata)->img.addr;
	npxl = ((WINDOW_W * WINDOW_H) / 2) + 1;
	rgb_to_hex(&(*idata)->celling);
	rgb_to_hex(&(*idata)->floor);
	while (--npxl > 0)
		*iaddr++ = (*idata)->celling.hcolour;
	npxl = ((WINDOW_W * WINDOW_H) / 2) + 1;
	while (--npxl > 0)
		*iaddr++ = (*idata)->floor.hcolour;
}

void	draw_map(t_game_data **data)
{
	(*data)->img.img = mlx_new_image((*data)->mlx, WINDOW_W, WINDOW_H);
	(*data)->img.addr = mlx_get_data_addr((*data)->img.img, &(*data)->img.bpp, \
		&(*data)->img.line_len, &(*data)->img.endian);
	draw_interior(data);
	if (!raycasting(data))
		return (print_message("tried raycasting\n"));
	mlx_put_image_to_window((*data)->mlx, (*data)->win_ptr,
		(*data)->img.img, 0, 0);
	mlx_destroy_image((*data)->mlx, (*data)->img.img);
	return ;
}
