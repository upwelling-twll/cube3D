#include "../../inc/execution.h"

static float	save_colour(t_game_data *data, float d, int c, float w)
{
	// data->txt_id = c;
	data->txt_w = w;
	return (d);
}

void	set_line(t_game_data *idata, int x, float v)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			fsrc;
	float			shift;

	h = (float)WINDOW_H / v;
	fsrc = 0.0f;
	shift = (float) idata->no_path.height / h;
	if (h > WINDOW_H)
	{
		fsrc = 0.5f * (h - WINDOW_H) / h * idata->no_path.height;
		h = WINDOW_H;
	}
	src = (unsigned int *) idata->no_path.addr;
	src += (int) ((float) idata->txt_w * idata->no_path.width);
	dst = (unsigned int *) idata->img.addr + x + (WINDOW_H - h) / 2 * WINDOW_W;
	while (h-- > 0)
	{
		*dst = *(src + ((int) fsrc) * idata->no_path.width);
		dst = dst + WINDOW_W;
		fsrc = fsrc + shift;
	}
}
