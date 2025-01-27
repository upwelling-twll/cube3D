#include "../inc/utils.h"

bool	iswall(char c)
{
	if (c == '1' || c == 'x')
		return (true);
	return (false);
}

int	get_isign(float n)
{
	if (n < 0.0f)
	{
		if (n > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (n < 0.000001f)
			return (0);
		else
			return (1);
	}
}
