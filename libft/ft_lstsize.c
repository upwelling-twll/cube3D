/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:43:46 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 16:46:48 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next;

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
