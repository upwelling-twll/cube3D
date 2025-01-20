#ifndef EXECUTION_H
# define EXECUTION_H

# include "./validation.h"
# include <math.h>

# define WINDOW_W 1024 //640 
# define WINDOW_H 512 //480
# define PI 3.14
# define FOV 1.047f //60 degrees

typedef	struct s_vec
{
	float	x;
	float	y;
}	t_vec;


typedef	struct s_ray
{
	int		sx;
	int		sy;
	t_vec	delta;
	t_vec	horiz;
	t_vec	vertic;
	float	hdist;
	float	vdist;
	float	vert_w;
	float	hor_w;	
}	t_ray;

//execution_dda.c
void	set_line(t_game_data *idata, int x, float v);

//execution_rcast.c
bool	raycasting(t_game_data **idata);

//execution_draw.c
void	draw_map(t_game_data **data);

//execution_strt.c
bool	execute(t_game_data **iData);

//execution_utils.c
int				get_isign(float n);

#endif
