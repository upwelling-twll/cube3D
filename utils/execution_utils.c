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
