#ifndef VALIDATION_H
# define VALIDATION_H

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "./utils.h"
# include "../mlx/mlx.h"

//validaiton_elem.c
bool	save_txtr(t_game_data **idata, char *path, char *type);
bool	correct_path(char *line);
bool	correct_colours(char *cpline);
char	*set_colour(char *line, int *rgb_compon);
bool	save_rgb(t_game_data **idata, char *line, char *type);
bool	is_unique(t_game_data **d, char *t);
bool	is_etoken(char *cpline, char **etype);

//validation_start.c
bool	valid_map(t_game_data **idata);
int		is_valid_elem(t_parsed_lines *pline, t_game_data **idata);
bool	valid_elements(t_game_data **idata);
bool	validation(t_game_data **idata);

#endif