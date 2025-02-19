/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_dda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:51:34 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/17 19:08:20 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execution.h"

void	set_line(t_game_data *idata, int x, float dist_to_wall)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			fsrc;
	float			shift;

	h = (float)WINDOW_H / dist_to_wall;
	fsrc = 0.0f;
	shift = (float) idata->cur_txt.height / h;
	if (h > WINDOW_H)
	{
		fsrc = 0.5f * (h - WINDOW_H) / h * idata->cur_txt.height;
		h = WINDOW_H;
	}
	src = (unsigned int *)idata->cur_txt.addr;
	src += (int)((float) idata->txt_w * idata->cur_txt.width);
	dst = (unsigned int *) idata->img.addr + x + (WINDOW_H - h) / 2 * WINDOW_W;
	while (h-- > 0)
	{
		*dst = *(src + ((int) fsrc) * idata->cur_txt.width);
		dst = dst + WINDOW_W;
		fsrc = fsrc + shift;
	}
}
