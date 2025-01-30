 #include "../../inc/execution.h"
# define SPEED	0.07f
void changed_position(t_game_data *data, float x, float y)
{
	if (data->mapLines[(int) data->sp_y][(int) x] == '0')
		data->sp_x = x;
	if (data->mapLines[(int) y][(int)data->sp_x] == '0')
		data->sp_y = y;
	draw_map(&data);
}


void	updating(t_game_data *data, float *x, float *y, float angle)
{
	float	speed;

	speed = SPEED;
	(*x) = speed * cosf(data->angle + angle);
	(*y) = speed * sinf(data->angle + angle);
}

int	key_hook(int keycode, t_game_data **data)
{
	float	x;
	float	y;

	x = (*data)->sp_x;
	y = (*data)->sp_y;

	// if ((*data)->keys.w)
	// 	updating((*data), &x, &y, M_PI_2);
	// if ((*data)->keys.s)
	// 	updating((*data), &x, &y, -1.f * M_PI_2);
	// if ((*data)->keys.a)
	// 	updating((*data), &x, &y, M_PI);
	// if ((*data)->keys.d)
	// 	updating((*data), &x, &y, 0.f);
	if (keycode == W)
		updating((*data), &x, &y, M_PI_2);
	if (keycode == S)
		updating((*data), &x, &y, -1.f * M_PI_2);
	if (keycode == A)
		updating((*data), &x, &y, M_PI);
	if (keycode == D)
		updating((*data), &x, &y, 0.f);
	changed_position((*data), x, y);
	// draw_map(data);
	return (0);
}