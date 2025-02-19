/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:15:11 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/17 19:15:11 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./parsing.h"
# include "../mlx/mlx.h"

//execution_utils.c
bool	iswall(char c);

//validation_map_edit.c
char	**replace_spaces(char **map, int max, int rows);
int		get_maxlen(char **map);

//validation_map_utils.c
char	**remove_last_nlsp(t_game_data **idata);
bool	end_of_map(char **map, int i);
int		get_array_size(char **array);
void	clean_map(char **map);
bool	is_valid_line(char *line);
bool	is_hero(char c);

//validation_elem_utils.c
char	*is_texture(char *line, char **types);
char	*is_rgb(char *line, char **types);
int		is_etoken_len(char *line);
bool	is_comma(char c);
char	*skip_comma(char *line);
char	*skip_digits(char *line);
bool	save_txt_data(t_txtr *elem, char *path, char *type);
//drop_message.c
void	print_message(char *text);
int		print_error(char *data, char *text);

//exit_program.c
void	clean_elem_lines(t_parsed_lines **initLines);
bool	exit_textures( char *line);
int		exit_program(char *text, t_game_data *initData);

//parsing_utils.c
bool	token_found(char *search, char *input);
bool	save_texture(char *type, char *line, t_game_data *initData);
bool	is_empty_line(char *line);
char	*skip_empty_lines(int fd);

//parse_map.c
bool	parse_map(char *path, int fd, t_game_data *initData, char *map_line);

//parsing_dbg.c
void	print_parsed_textures(t_parsed_lines *initLines);
void	print_parsed_map(char **mapLines);

//parse_textures.c
void	clean_line(char *line);
int		ft_lstsize_pl(t_parsed_lines *lst);
t_parsed_lines	*ft_lstlast_pl(t_parsed_lines *lst);
int		search_elements(char *line, t_game_data *initData, int pe);
bool	parse_textures(int fd, t_game_data *initData, char **map_line);

//skip_tab_spaces.c
bool	is_eof(char c);
bool	is_tab_or_space(char c);
bool	is_end_of_line(char c);
char	*skip_non_spaces(char *line);
char	*skip_tab_spaces(char *line);

#endif