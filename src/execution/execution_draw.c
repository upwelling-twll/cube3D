#include "../../inc/execution.h"

void	rgb_to_hex(t_rgb *text)
{
	text->hcolour = (text->red << 16) | (text->green << 8) | text->blue;
	//  text.hcolour = 0xDC6400;
	printf("hex colour: %x\n", text->hcolour);
}

void	draw_interior(t_game_data **idata)
{
	unsigned int	*iaddr;
	unsigned int	npxl;

	iaddr = (unsigned int*)(*idata)->img.addr;
	npxl = ((WINDOW_W * WINDOW_H) / 2) + 1;
	rgb_to_hex(&(*idata)->celling);
	rgb_to_hex(&(*idata)->floor);
	// printf("hex colour: %x\n", (*idata)->celling.hcolour);
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
	//might add if (*data)->img.img != NULL : ft_bzero(img.addr)
	// practice_rcasting(data);
	draw_interior(data);
	printf("complete draw interior\n");
	if (!raycasting(data))
		return (print_message("tried raycasting\n"));
	mlx_put_image_to_window((*data)->mlx,(*data)->win_ptr, (*data)->img.img, 0, 0);
	mlx_destroy_image((*data)->mlx, (*data)->img.img);
	return ;
}