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

bool	has_space_around(char **map, int y, int x)
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

bool	on_eage(int y, int x, int height, int widht)
{

	if (y == 0 || y >= height)
		return (print_message("0 on eage"), true);
	else if (x == 0 || x >= widht)
		return (print_message("0 on eage"), true);
	else
		return (false);
}

bool	check_walls(char **map, int height, int widht)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//todo
	printf("function dfs_check_walls:STUB\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || is_hero(map[i][j]))
			{
				if (on_eage(i, j, height, widht) || has_space_around(map, i, j))
				{
					printf("check walls return false, line:%s\n", map[i]);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);	
}
