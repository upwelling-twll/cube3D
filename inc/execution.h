#ifndef EXECUTION_H
# define EXECUTION_H

# include "./validation.h"

# define WINDOW_W 1024 //640 
# define WINDOW_H 512 //480
# define PI 3.14
# define VIEW_ANGLE 1.047f //60 degrees  

//execution_dda.c

//execution_rcast.c
bool	raycasting(t_game_data **idata);

//execution_draw.c
void	draw_map(t_game_data **data);

//execution_strt.c
bool	execute(t_game_data **iData);

//practice.c
void practice_rcasting(t_game_data **data);

#endif
