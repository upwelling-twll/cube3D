#include "../../inc/utils.h"

bool	is_wall(char *line)
{
	int	i;
	int	walls;
	int	spaces;

	i = 0;
	walls = 0;
	spaces = 0;
	while (line && line != '\n')
	{
		if (line[i] == '1')
			walls++;
		if (line[i] == ' ')
			spaces++;
		i++;
	}
	if (walls < 1 || walls+spaces < i)
		return (false);
	return (true);
}

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1') //0 - space, 1 - wall
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true); //N,S,E,W - spawning orientation
	return (false);
}

bool have_walls(char **map, t_game_data *mapInfo)
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


//fist argument is a file called  "scene description file with the .cub"