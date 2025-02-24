/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:32:04 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:59:20 by ssiddiqu         ###   ########.fr       */
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
bool	check_walls(char **map, int height, int widht);

//validation_hero_utils.c
bool	good_pos(char **map);

//validation_map.c
bool	has_one_hero(char **lmap);
bool	is_wall(char *line);
bool	replace_sp_to_x(t_game_data **idata, int rows);
bool	is_valid_map(t_game_data **idata, char **lmap);

//validation_str_helpers.c
bool	is_comma(char c);
char	*skip_comma(char *line);

//validaiton_elem.c
bool	save_txtr(t_game_data **idata, char *path, char *type);
bool	correct_path(char *line);
bool	correct_colours(char *cpline);
bool	is_unique(t_game_data **d, char *t);
bool	is_etoken(char *cpline, char **etype);

//validation_start.c
bool	valid_map(t_game_data **idata);
int		is_valid_elem(t_parsed_lines *pline, t_game_data **idata);
bool	valid_elements(t_game_data **idata);
bool	validation(t_game_data **idata);

//validation_colours.c
char	*set_colour(char *line, int *rgb_compon);
bool	save_rgb(t_game_data **idata, char *line, char *type);

#endif