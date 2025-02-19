/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:21:56 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/17 19:21:57 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./utils.h"
# include "../mlx/mlx.h"

//validation_walls.c
// bool	has_internal_walls(char **map);
bool	check_walls(char **map, int height, int widht);
//validation_map.c
bool	has_one_hero(char **lmap);
bool	is_wall(char *line);
bool	replace_sp_to_x(t_game_data **idata, int rows);
bool	compare_maps(char **spmap, char **vmap);
bool	is_valid_map(t_game_data **idata, char **lmap);

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