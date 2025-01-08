#include "../../inc/execution.h"

# define WINDOW_W 640
# define WINDOW_H 480

void	get_spawn_posit(t_game_data **iData)
{
	int	x;
	int	y;

	y = 0;
	while ((*iData)->mapLines[y])
	{
		x = 0;
		while ((*iData)->mapLines[y][x])
		{
			if (is_hero((*iData)->mapLines[y][x]))
			{
				(*iData)->sp_y = y;
				(*iData)->sp_x = x;
			}
			x++;
		}
		y++;
	}
	return ;
}

bool	set_image(t_game_data **iData, t_txtr texture)
{
	texture.img = mlx_xpm_file_to_image((*iData)->mlx, texture.path, &texture.width, &texture.height);
	if (!texture.img)
		return (false);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, &texture.line_len, &texture.endian);
	return (true);
}

bool	init_sources(t_game_data **iData)
{
	if (!set_image(iData, (*iData)->no_path))
		return (false);
	if (!set_image(iData, (*iData)->so_path))
		return (false);
	if (!set_image(iData, (*iData)->we_path))
		return (false);
	if (!set_image(iData, (*iData)->ea_path))
		return (false);
	return (true);
}

bool	execute(t_game_data **iData)
{
	get_spawn_posit(iData);
	(*iData)->mlx = mlx_init();
	if (!init_sources(iData))
		return (print_message("execution: failed init sources"), false);
	(*iData)->win_ptr = mlx_new_window((*iData)->mlx, WINDOW_W, WINDOW_H, "Cube_3D");
	return (true);
}