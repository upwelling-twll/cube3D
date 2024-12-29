#include "../inc/utils.h"

void	print_validated_map(char **mapLines)
{
	int	i;

	i = 0;
	printf("\n		~Validated map~	 \n");
	if (!mapLines)
	{
		printf("	*** Empty mapLines ***\n");
		return ;
	}
	while (mapLines[i] != NULL)
	{
		printf("%s\n$", mapLines[i]);
		i++;
	}
}
