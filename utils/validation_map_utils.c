#include "../inc/validation.h"

bool	is_hero(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

bool	is_valid_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!line)
		return (false);
	len = ft_strlen(line);
	while (i < len && (line[i] == ' ' || line[i] == '1' || line[i] == '0' || is_hero(line[i]) || line[i] == '\n'))
		i++;
	if (line[i] == '\0')
		return(true);
	else
		return (false);
}

bool	end_of_map(char **map, int i)
{
	i++;
	if (!(map[i]))
		return (true);
	while (map[i])
	{
		if (is_empty_line(map[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

void	clean_map(char **map)
{
	int	i;
	printf("clean map called\n");
	i = 0;
	if (!map || !map[0])
		return ;
	// printf("start clean\n");
	while(map[i])
	{
		// printf("clean line:%s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

char	**copy_map(t_game_data **idata, char **map, int rows)
{
	char **nmap;
	int	i;

	i  = 0;
	nmap = malloc(sizeof(char *) * (rows + 1));
	if (!nmap)
		return (NULL);
	while (i < rows)
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			nmap[i] = ft_strndup(map[i], (ft_strlen_sst(map[i])) - 1);
		else
			nmap[i] = ft_strdup(map[i]);
		i++;
	}
	nmap[i] = NULL;
	clean_map((*idata)->mapLines);
	(*idata)->mapLines = nmap;
	return (nmap);
}

char	**remove_last_nlsp(t_game_data **idata)
{
	char	**map;
	int		i;

	if (!idata)
		return (NULL);
	i = 0;
	map = (*idata)->mapLines;
	while (map[i])
	{
		if (!is_empty_line(map[i]))
		{
			if (!is_valid_line(map[i]))
				return (print_message("line is invalid"), NULL);
			i++;
		}
		else if (!end_of_map(map, i))
			return (print_message("error:next lines are unempty"), NULL);
		else
			break;
	}
	return (copy_map(idata, map, i));
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[0])
		return(0);
	while (array[i])
		i++;
	return (i);
}

