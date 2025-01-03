#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// typedef struct s_lmap
// {
// 	char	*line;
// 	int		nrow;
// 	int		nlenght;
// 	bool	space;

// }		t_lmap;
typedef	struct s_parsed_lines
{
	char	*line;
	int		id;

	struct s_parsed_lines	*next;
}		t_parsed_lines;

typedef	struct s_rgb
{
	int		red;
	int		green;
	int		blue;

	bool	status;
}		t_rgb;

typedef struct s_txtr
{
	char	*type;
	char	*path;
	int		fd;
	bool	status;
}		t_txtr;

typedef struct s_game_data
{
	t_txtr			no_path;
	t_txtr			so_path;
	t_txtr			we_path;
	t_txtr			ea_path;

	t_rgb			floor;
	t_rgb			celling;

	// t_lmap			**map;

	t_parsed_lines **initLines;
	char			**mapLines;
} 		t_game_data;

//verif_map.c

//verif_elements.c
bool	good_file(char *file_path);

//verif_file.c
bool	verify_file_xpm(char *input);
bool 	verify_file_cub(char *input);
bool	correct_file_type(char *input, char *type);
bool	verify_file(char *input);

//parsing_start.c
void	clean_line(char *line);
bool	parse_textures(int fd, t_game_data *initData, char **map_line);
bool	parsing(char *path, t_game_data **initData);

#endif