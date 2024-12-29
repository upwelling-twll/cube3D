#include "../inc/validation.h"

char	**replace_spaces(char **map, int *rows_len, int max, int rows)
{
	char **nmap;
	int	i;

	i  = 0;
	nmap = malloc(sizeof(char *)* rows + 1);
	if (!nmap)
		return (NULL);
	while (i < rows)
	{
		//replacing sp by x
		//maximizing the length of each column to max by adding x (sp)
	}
	nmap[i] = NULL;
	clean_map((*idata)->mapLines);
	(*idata)->mapLines = nmap;
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
