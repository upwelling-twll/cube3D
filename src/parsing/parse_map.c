#include "../../inc/utils.h"

char	*skip_textures(int fd)
{
	char	*line;
	int		nelem;
	int		minimum_elements;

	nelem = 0;
	minimum_elements = 6;
	line = skip_empty_lines(fd);
	while (line && !is_eof(*line) && nelem < minimum_elements)
	{
		nelem++;
		if (line)
			free(line);
		line = skip_empty_lines(fd);
	}
	return (line);
}

bool	save_map(char *path, size_t nlines, t_game_data *data)
{
	int	fd;
	char	*map_line;
	size_t		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	map_line = skip_textures(fd);
	if (!map_line)
		return (false);
	data->mapLines = malloc(sizeof(char*) * (nlines + 1));
	i = 0;
	while (map_line && i < nlines)
	{
		data->mapLines[i] = ft_strdup(map_line);
		i++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	if (map_line)
		free(map_line);
	data->mapLines[i] = NULL;
	close(fd);
	return (true);
}

bool	go_through_map(char *path, int fd, char *line, t_game_data* data)
{
	size_t	nlines;

	nlines = 1;
	// printf("go_through map\n");
	// printf("opened fd\n");
	while (line && !is_eof(*line))
	{
		free(line);
		line = get_next_line(fd);
			nlines++;
	}
	close(fd);
	if (line)
		free(line);
	printf("Found %zu map lines to save\n", nlines);
	if (!save_map(path, nlines, data) || !data->mapLines || data->mapLines[0] == NULL)
		print_message("Could not save map\n");
	else
		printf("Saved %zu map lines\n", nlines);
	return (true);
}

bool	parse_map(char *path, int fd, t_game_data *initData, char *map_line)
{
	map_line = skip_empty_lines(fd);
	if (!map_line || is_eof(*map_line))
		return (print_error(NULL, "Parse map:did not find any map to copy"));
	if (!go_through_map(path, fd, map_line, initData))
		return (print_error(NULL, "Parse map:did not find any map to copy"));
	return (true);
}
