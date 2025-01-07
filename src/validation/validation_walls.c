#include "../inc/validation.h"

char	get_last_nonspace(char *line)
{
	//todo;
	if (!line)
		return (line[0]);
	return ('1');
}

bool	has_space_around(char **map, int y, int x)
{
	//todo;
	// printf("has_space_around check\n");
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
	// printf("start on eage\n");
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
	// printf("function check_walls:STUB\n");
	while (map[i])
	{
		// printf("check wall, line:%s\n", map[i]);
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
