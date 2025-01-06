#include "../inc/utils.h"

void	print_validation_map(char **mapLines, char *map_name)
{
	int	i;

	i = 0;
	printf("\n		~%s map~	 \n", map_name);
	if (!mapLines)
	{
		printf("	*** Empty map ***\n");
		return ;
	}
	while (mapLines[i] != NULL)
	{
		printf("%s$\n", mapLines[i]);
		i++;
	}
}
