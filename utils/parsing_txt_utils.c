/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:31 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:26:13 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	clean_line(char *line)
{
	if (line)
	{
		free(line);
	}
}

int	ft_lstsize_pl(t_parsed_lines *lst)
{
	int				i;
	t_parsed_lines	*next;

	if (lst == NULL)
		return (0);
	next = lst->next;
	i = 1;
	while (next != NULL)
	{
		next = next -> next;
		i++;
	}
	return (i);
}

t_parsed_lines	*ft_lstlast_pl(t_parsed_lines *lst)
{
	int	i;

	if (!lst)
		return (lst);
	i = ft_lstsize_pl(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

int	start_list(char *line, t_game_data *initData)
{
	if (!((*initData->initlines)->line = ft_strdup(line)))
	{
		if ((*initData->initlines))
			free((*initData->initlines));
		return (0);
	}
	else if ((*initData->initlines)->line != NULL)
	{
		(*initData->initlines)->next = NULL;
		return (1);
	}
	return (0);
}

int	append_to_list(char *line, t_game_data *initData)
{
	t_parsed_lines *new;

	new = malloc(sizeof(t_parsed_lines));
	if (!new)
		return (0);
	new->next = NULL;
	(ft_lstlast_pl((*initData->initlines)))->next = new;
	if (!((ft_lstlast_pl((*initData->initlines))->line = ft_strdup(line))))
	{
		if (initData->initlines)
			clean_elem_lines(initData->initlines);
		return (0);
	}
	else
		return (1);
}
