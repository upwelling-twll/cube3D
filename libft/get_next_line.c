/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 23:00:31 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*exit_gnl(t_bits *base_bits, char **buf, char *result)
{
	t_bits	*tmp;
	t_bits	*tmp2;

	if (base_bits)
	{
		while (base_bits)
		{
			tmp = base_bits->next;
			if (!base_bits)
				break ;
			tmp2 = base_bits;
			if (base_bits)
			{
				free(tmp2->line_bit);
				free(tmp2);
			}
			base_bits = tmp;
		}
	}
	if (*buf)
		free(*buf);
	return (result);
}

t_bits	*before_end(char *buf, size_t i)
{
	t_bits	*new_bit;
	size_t	len;

	len = 0;
	new_bit = malloc(sizeof(t_bits));
	i = i + 1;
	if (!new_bit)
		return (NULL);
	new_bit->line_bit = malloc(sizeof(char) * i + 1);
	if (!new_bit->line_bit)
		return (NULL);
	if (i + 1 > 0)
	{
		while (buf[len] && len < (i + 1 - 1))
		{
			new_bit->line_bit[len] = buf[len];
			len++;
		}
		new_bit->line_bit[len] = 0;
	}
	new_bit->len = i;
	new_bit->next = NULL;
	return (new_bit);
}

int	parse_one_bit(t_bits **bb, char *buf, char **rem_line, ssize_t *fe)
{
	ssize_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (i == *fe)
	{
		if (*bb)
			(lst_magic(NULL, *bb))->next = lst_magic(ft_strldup(buf, fe), NULL);
		else if (ft_lsbsize(*bb) == 0)
			*bb = lst_magic(ft_strldup(buf, fe), NULL);
		lst_magic(NULL, *bb)->len = i;
		return (0);
	}
	if (*bb)
		(lst_magic(NULL, *bb))->next = before_end(buf, i++);
	else
	{
		*bb = before_end(buf, i++);
		lst_magic(NULL, *bb)->len = i;
	}
	if (!(i == *fe) && buf[i - 1] == '\n')
		*rem_line = ft_strldup(buf + i, fe);
	return (1);
}

char	*fill_buf(char **rem_line, char **buf, ssize_t *fe, int fd)
{
	size_t	len;
	char	*bufc;

	if (*rem_line)
	{
		*buf = ft_strldup(*rem_line, fe);
		free(*rem_line);
		*rem_line = NULL;
		return (*buf);
	}
	*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(*buf))
		return (NULL);
	bufc = *buf;
	len = (sizeof(char)) * BUFFER_SIZE + 1;
	while (len--)
		*bufc++ = (unsigned char)0;
	*fe = read(fd, *buf, BUFFER_SIZE);
	if (*fe < 0)
		return (NULL);
	(*buf)[*fe] = '\0';
	return (*buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	t_bits		*base_bits;
	static char	*rem_line;
	ssize_t		fe;

	fe = 0;
	base_bits = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!fe)
	{
		fe = 0;
		if (fill_buf(&rem_line, &buf, &fe, fd) == NULL)
			return (exit_gnl(base_bits, &buf, NULL));
		if (fe <= 0)
			break ;
		fe = parse_one_bit(&base_bits, buf, &rem_line, &fe);
		if (fe < 0)
			return (exit_gnl(base_bits, &buf, NULL));
		if (!fe)
			free(buf);
	}
	line = fill_line(base_bits);
	return (exit_gnl(base_bits, &buf, line));
}
