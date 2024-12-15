#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_lmap
{
	char	*line;
	int		nrow;
	int		nlenght;
	bool	space;

}		t_lmap;

typedef	struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;


typedef struct s_game_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	t_rgb	*floor;
	t_rgb	*celling;

	t_lmap	**map;
} 		t_game_data;


//verif_map.c

//verif_elements.c
bool	good_file(char *file_path);

//verif_file.c
bool	verify_file(char *input);

//parsing_start.c
void	clean_line(char *line);
bool	parse_textures(int fd, t_game_data *initData);
bool	parsing(char *path);

#endif