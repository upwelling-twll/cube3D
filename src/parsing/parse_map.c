#include "../../inc/utils.h"

bool	is_map(char *line)
{
	char	*cpline;

	cpline = line;
	skip_tab_spaces(cpline);
	while (!is_eof(*cpline) && !is_end_of_line(*cpline) && !is_tab_or_space(*line))
	{
		if (is_wall(line))
		{
			printf("wall map line found:\n%s\n", line);
			return (true);
		}
		else if (is_middle_line(cpline))
		{
			printf("middle map line found:\n%s\n", line);
			return (true);
		}
	}
}

bool	copy_map(char *path, t_game_data *initData, int n)
{
	int		fd;
	char	*line;
	int		i;
	
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd > 2)
	{
		line = getnextline(fd);
		while (!is_map(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		initData->map = malloc(sizeof(t_lmap)*n + 1);
		while (i < n)
		{
			initData->map[i] = ft_strdup(line);
			i++;
			free(line);
			line = get_next_line(fd);
		}
		if (line)
			free(line);
		return (true);
	}
	return (false);
}

bool	go_through_map(char *path, int fd, t_game_data* data)
{
	char	*line;
	int		nline;

	line = getnextline(fd);
	while (is_map(line))
	{
		free(line);
		nline++;
		get_next_line(fd);
	}
	if (trash_after_map(line, fd))
	{
		clean_verif_map(line, fd);
		return (print_error(NULL, "GTM:trash after map"));
	}
	if (line)
		free(line);
	close(fd);
	if (!copy_map(path, data, nline))
		return (print_error(NULL, "GTM:could not copy map"));
	else
		return (true);
	return (false);
}

bool	parse_map(char *path, int fd, t_game_data *initData)
{
	if (fd)
		printf("zaglushka for save map\n");
	if (!go_through_map(path, fd, initData))
		return (print_error(NULL, "Parse map:did not find correcct map to copy"));
	
	return (false);
}