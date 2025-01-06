#include "../inc/validation.h"

char	**replace_spaces(char **map, int max, int rows)
{
	char	**nmap;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nmap = malloc(sizeof(char *)* rows + 1);
	if (!nmap)
		return (NULL);
	while (i <= rows)
	{
		j = 0;
		nmap[i] = malloc(sizeof(char) * max + 1);
		if (!nmap[i])
			return (clean_map(nmap), NULL);
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ')
				nmap[i][j] = 'x';
			else
				nmap[i][j] = map[i][j];
			j++;
		}
		while (j < max)
		{
			nmap[i][j] = 'x';
			j++;
		}
		nmap[i][j] = '\0';
		i++;
	}
	nmap[i] = NULL;
	return (nmap);
}

int	 get_maxlen(char **map, int **rows_len, int rows)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	(*rows_len) = malloc(sizeof(int) * rows);
	if (!rows_len)
		return (0);
	while (map[i])
	{
		(*rows_len)[i] = ft_strlen(map[i]);
		if (max < (*rows_len)[i])
			max = (*rows_len)[i];
		i++;
	}
	return (max);
}
