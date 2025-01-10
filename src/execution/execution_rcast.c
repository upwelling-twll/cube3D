#include "../../inc/execution.h"

t_ray	set_ray_data(t_game_data *data, float view)
{
	t_ray	ray;

	ray.d.x = cos(view);
	ray.d.y = -sin(view);
	ray.s.x = 
}

float	cast_ray(t_game_data **idata, float view)
{
	t_ray	ray;

	ray = set_ray_data((*idata), view);

}

bool	raycasting(t_game_data **idata)
{
	int		i;
	float	view;
	float	dview;

	view = (*idata)->angle - VIEW_ANGLE / 2;
	dview = VIEW_ANGLE / (WINDOW_W - 1);
	i = -1;
	while (i < WINDOW_W)
	{
		get_line(idata, i, cast_ray(idata, view) * cos((*idata)->angle - view));
		view = view + dview;
		i++;
	}
	return (false);
}