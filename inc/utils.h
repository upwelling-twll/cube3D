#ifndef UTILS_H
# define UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "./parsing.h"
# include "../mlx/mlx.h"

//drop_message.c
void	print_message(char *text);
int		print_error(char *data, char *text);

//exit_program.c
int		exit_program(char *text);

//parsing_utils.c
bool	token_found(char *search, char *input);
bool	save_texture(char *type, char *line,  t_game_data *initData);
bool	is_empty_line(char *line);
char	*skip_empty_lines(int fd);
bool	exit_textures( char *line, t_game_data *initData);

//parse_map.c
bool	parse_map(char *path, int fd, t_game_data *initData, char *map_line);

//parsing_dbg.c
void	print_parsed_textures(t_parsed_lines *initLines);
void	print_parsed_map(char **mapLines);

//parse_textures.c
void			clean_line(char *line);
int				ft_lstsize_pl(t_parsed_lines *lst);
t_parsed_lines	*ft_lstlast_pl(t_parsed_lines *lst);
int 			search_elements(char *line,  t_game_data *initData, int pe);
bool			parse_textures(int fd, t_game_data *initData, char **map_line);


//skip_tab_spaces.c
bool	is_eof(char c);
bool	is_tab_or_space(char c);
bool	is_tab_or_space(char c);
char	*skip_tab_spaces(char *line);

#endif