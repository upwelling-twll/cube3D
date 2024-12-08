/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:43:28 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 16:46:23 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	void	*tmp;

	newlist = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		if (tmp)
			ft_lstadd_back(&newlist, ft_lstnew(tmp));
		else
		{
			ft_lstclear(&newlist, del);
			free(newlist);
			return (newlist);
		}
		lst = lst->next;
	}
	return (newlist);
}
