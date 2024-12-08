/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 22:59:18 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lsbsize(t_bits *lst)
{
	size_t		size;
	t_bits		*next;

	size = 0;
	if (lst == NULL)
		return (0);
	if (lst->next)
	{
		next = lst->next;
		size = 1;
	}
	else
		return (1);
	while (next != NULL)
	{
		size++;
		next = next -> next;
	}
	return (size);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	k = i + j;
	j = 0;
	while (i < k)
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

t_bits	*lst_magic(void *content, t_bits *lst)
{
	t_bits	*list;
	size_t	i;

	if (content)
	{
		list = malloc(sizeof(t_bits));
		if (!list)
			return (NULL);
		list -> line_bit = content;
		list -> next = NULL;
		return (list);
	}
	if (!lst)
		return (lst);
	i = ft_lsbsize(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

char	*ft_strldup(const char *s1, ssize_t *fe)
{
	char	*cp;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	*fe = len;
	len = len + 1;
	cp = malloc(len);
	if (!cp)
		return (NULL);
	while (i != len)
	{
		*(char *)(cp + i) = *(char *)(s1 + i);
		i++;
	}
	return (cp);
}

char	*fill_line(t_bits *bits)
{
	size_t		all_len;
	size_t		nodes_toprint;
	char		*line;
	t_bits		*cpbits;

	all_len = 0;
	nodes_toprint = ft_lsbsize(bits);
	cpbits = bits;
	while (cpbits != NULL)
	{
		all_len += cpbits->len;
		cpbits = cpbits -> next;
	}
	if (all_len == 0)
		return (NULL);
	line = malloc(sizeof(char) * all_len + 1);
	line[0] = '\0';
	while (nodes_toprint)
	{
		ft_strcat(line, bits->line_bit);
		bits = bits->next;
		nodes_toprint--;
	}
	return (line);
}
