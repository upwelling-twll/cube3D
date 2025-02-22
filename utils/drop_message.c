#include "../inc/utils.h"

void	print_message(char *text)
{
	printf("%s\n", text);
}

int	print_error(char *data, char *text)
{
	if (data)
		printf("ERROR: %s. %s\n", data, text);
	else if (data == NULL)
		printf("ERROR: %s\n", text);
	return (1);
}

