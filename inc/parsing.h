/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:20:31 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:21:43 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_parsed_lines
{
	char					*line;
	int						id;

	struct s_parsed_lines	*next;
}		t_parsed_lines;

typedef struct s_rgb
{
	unsigned int	hcolour;

	int				red;
	int				green;
	int				blue;

	bool			status;
}		t_rgb;

typedef struct s_txtr
{
	char	*type;
	char	*path;
	int		fd;
	bool	status;

	void	*img;
	void	*addr;
	int		endian;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
}		t_txtr;

typedef struct s_img
{
	void			*img;
	void			*addr;
	int				endian;
	int				bpp;
	int				width;
	int				height;
	int				line_len;
}		t_img;

typedef struct s_game_data
{
	t_txtr			no_path;
	t_txtr			so_path;
	t_txtr			we_path;
	t_txtr			ea_path;

	t_rgb			floor;
	t_rgb			celling;
	int				txt_id;
	float			txt_w;
	t_txtr			cur_txt;

	t_parsed_lines	**initlines;
	char			**maplines;
	int				map_height;
	int				map_widht;

	float			sp_x;
	float			sp_y;
	float			angle;
	void			*mlx;
	void			*win_ptr;
	t_img			img;
}		t_game_data;

//verif_map.c

//verif_elements.c
bool	good_file(char *file_path);

//verif_file.c
bool	verify_file_xpm(char *input);
bool	verify_file_cub(char *input);
bool	correct_file_type(char *input, char *type);
bool	verify_file(char *input);

//parsing_start.c
void	clean_line(char *line);
bool	parse_textures(int fd, t_game_data *initData, char **map_line);
bool	parsing(char *path, t_game_data **initData);

#endif