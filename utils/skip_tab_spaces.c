#include "../inc/utils.h"

bool	is_eof(char c)
{
	if (!c)
		return (true);
	if (c == '\0')
		return (true);
	else
		return (false);
}

bool	is_tab_or_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

bool	is_end_of_line(char c)
{
	if (c == '\0')
		return (true);
	else
		return (false);
}

char*	skip_non_spaces(char *line)
{
	if (!is_end_of_line(*line))
	{
		while (*line && !is_tab_or_space(*line))
			line++;
	}
	return (line);
}

char*	skip_tab_spaces(char *line)
{
	if (!is_end_of_line(*line))
	{
		while (is_tab_or_space(*line))
			line++;
	}
	// printf("skip tspaces:%s", line);
	return (line);
}

