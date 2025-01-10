#ifndef EXECUTION_H
# define EXECUTION_H

# include "./validation.h"

# define WINDOW_W 640
# define WINDOW_H 480
# define PI 3.14
//execution_dda.c

//execution_rcast.c
bool	raycasting(t_game_data **idata);

//execution_draw.c
void	draw_map(t_game_data **data);

//execution_strt.c
bool	execute(t_game_data **iData);

#endif
