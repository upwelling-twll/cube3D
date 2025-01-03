#include "../inc/utils.h"

void	print_validation_map(char **mapLines, char *txt)
{
	int	i;

	i = 0;
	printf("\n		~%s map~	 \n", txt);
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
