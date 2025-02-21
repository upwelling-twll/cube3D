/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:55 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:51:07 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "./validation.h"
# include <math.h>

# define WINDOW_W 1024 //640 
# define WINDOW_H 512 //480
# define PI 3.14
# define FOV 1.047f //60 degrees
# define W	13
# define A	0
# define S	1
# define D	2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define ESC	53

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_ray
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
float	set_ray(t_game_data *data, float v);

//execution_draw.c
void	draw_map(t_game_data **data);

//execution_strt.c
bool	execute(t_game_data **iData);
void	get_angle(t_game_data **iData, char c);

//execution_utils.c
int		get_isign(float n);

//movements.c
int		key_hook(int keycode, t_game_data **data);
int		rotate(int keycode, t_game_data *data);
bool	is_free_space(char **map, float x, float y);

int		destroy_prog(t_game_data *iData);

#endif
