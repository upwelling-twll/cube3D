#include "../inc/utils.h"

bool	is_eof(char c)
{
	if (c == '\0')
		retun (true);
	else
		return (false);
}


bool	is_tab_or_space(char c)
{
	if (c == ' ' || c == '\t')
		retun (true);
	else
		return (false);
}

bool	is_end_of_line(char c)
{
	if (c == '\n')
		return (true);
	else
		return (false);
}

void	skip_tab_spaces(char *line)
{
	while (!is_end_of_line(*line))
	{
		while (is_tab_or_space(*line))
			line++;
	}
}
