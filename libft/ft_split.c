/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:45:01 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 22:58:50 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sepamount(const char *s, char c)
{
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		a++;
	}
	if (i > 0 && s[i - 1] == c)
		a--;
	return (a);
}

static size_t	ft_singleword(const char *s, const char c)
{
	size_t	wordlen;

	wordlen = 0;
	if (!s)
		return (0);
	while (*s && *s != c)
	{
		wordlen++;
		s++;
	}
	return (wordlen);
}

static char	**ft_cleanstr(char **arr, size_t n, int flag)
{
	size_t	i;

	if (flag)
	{
		if (n == 0)
			return (NULL);
		else
			arr[n] = NULL;
		return (arr);
	}
	if (arr)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] != NULL)
				free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

static char	**ft_fillstr(char **str, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s == '\0')
			continue ;
		str[i] = malloc(sizeof(char) * ft_singleword(s, c) + 1);
		if (str[i] == NULL)
			return (ft_cleanstr(str, i, 0));
		j = 0;
		while (*s != '\0' && *s != c)
		{
			str[i][j] = *s;
			s++;
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	str = ft_cleanstr(str, i, 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_sepamount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	if (ft_fillstr(str, s, c) == NULL)
	{
		free(str);
		str = NULL;
	}
	return (str);
}
