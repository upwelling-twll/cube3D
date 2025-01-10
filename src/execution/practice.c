#include "../../inc/execution.h"
# define SCALE 100
bool	close_to(int tx, int ty, int x, int y)
{
	if (x == tx && y == ty)
		return (true);
	if (x == tx - 1 && y == ty)
		return (true);
	if (x == tx + 1 && y == ty)
		return (true);
	if (x == tx && y == ty - 1)
		return (true);
	if (x == tx  && y == ty + 1)
		return (true);
	return (false);
}

void draw_player(int x, int y, t_game_data **idata)
{
    unsigned int *iaddr;
    int cx, cy;
    int size = 10;  // Size of the player symbol (5x5 pixels)
    int startX = x - size / 2;  // Start drawing from the left side of the player
    int startY = y - size / 2;  // Start drawing from the top side of the player

    iaddr = (unsigned int*)(*idata)->img.addr;

    printf("draw_player: x = %i, y = %i\n", x, y);

    // Loop through a 5x5 grid of pixels centered around (x, y)
    for (cy = startY; cy < startY + size; cy++)
    {
        for (cx = startX; cx < startX + size; cx++)
        {
            if (close_to(x, y, cx, cy))  // You might want to check if this is part of the player's area
            {
                printf("close to\n");
                // Draw player as a yellow square
                *(iaddr + cy * WINDOW_W + cx) = 0xFFCC00;  // Set the pixel color
            }
        }
    }
}
void	practice_rcasting(t_game_data **idata)
{
	unsigned int	*iaddr;
	unsigned int	npxl;
	unsigned int	linelen;

	iaddr = (unsigned int*)(*idata)->img.addr;
	linelen = 0;
	npxl = ((WINDOW_W * WINDOW_H)) + 1;
	while (--npxl > 0)
		*iaddr++ = 0x808080;
	draw_player((*idata)->sp_x * 100, (*idata)->sp_y * 100, idata);
}