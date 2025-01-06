#include "../inc/validation.h"

char	get_last_nonspace(char *line)
{
	//todo;
	if (!line)
		return (line[0]);
	return ('1');
}

/// @brief check line starts and ends with 1
/// @param map 
/// @return true if line has walls, otherwise - false
bool	has_internal_walls(char **map)
{
	int		i;
	char	last_nonspace;
	char	wall;
	char	**cpmap;

	i = 0;
	cpmap = map;
	while (map[i])
	{
		wall = skip_tab_spaces(cpmap[i])[0];
		if (wall != '1')
			return (false);
		last_nonspace = get_last_nonspace(map[i]);
		if (last_nonspace != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	has_space_around(char **map, int x, int y)
{
	//todo;
	printf("has_space_around check\n");
	if (map[y][x])
	{
		if (map[y][x+1] == 'x')
			return (true);
		else if (map[y][x-1] == 'x')
			return (true);
		else if (map[y+1][x] == 'x')
			return (true);
		else if (map[y-1][x] == 'x')
			return (true);
	}
	return (false);
}

bool	check_walls(char **map, char p, char r)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//todo
	if (map && p && r)
		printf("function dfs_check_walls:STUB\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
			{
				if (has_space_around(map, i, j))
				{
					printf("check walls return false\n");
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);	
}
