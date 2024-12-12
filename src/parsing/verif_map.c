bool	is_valid_char(char c)
{
	if (c == '0' || c == '1') //0 - space, 1 - wall
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true); //N,S,E,W - spawning orientation
	return (false);
}

bool have_walls(char **map, t_map_data *mapInfo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !mapInfo)
		return (error_message("No map or mapInfo"));
	while (map[i][j])
	{
		j = mapInfo->line_length[i];
		if (map[i][0] == '1' && map[i][j] == '1')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	copy_scene_description(int fd, t_scene* data)
{
	char	*line;
	int		nline;

	line = getnextline(fd);
	while (line)
	{
		if (verif_elements(line))
		{	
			append_to_list(data->elements, line);
			free(line);
			nline++;
		}
		else
		{
			clean_data();
			printf("invalid map line[%d]\n", nline);
			free(line);
			return (false);
		}
	}
}

//fist argument is a file called  "scene description file with the .cub"