#include "../inc/utils.h"

void	print_message(char *text)
{
	printf("%s\n", text);
}

int	print_error(char *data, char *text)
{
	if (data)
		printf("%s. %s\n", data, text);
	else if (data == NULL)
		printf("%s\n", text);
	return (1);
}

