/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:42:52 by nmagdano          #+#    #+#             */
/*   Updated: 2023/08/26 16:48:05 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;
	t_list	*next;

	i = ft_lstsize(*lst);
	while (i)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
		i--;
	}
}

// int main(int argc, char *argv[])
// {
//    t_list *newlist;
//
//    newlist = ft_lstnew(argv[1]);
//    newlist -> next = ft_lstnew(argv[2]);
//    newlist -> next -> next = ft_lstnew(argv[3]);
//    newlist -> next -> next -> next = ft_lstnew(argv[4]);
//    printf("%s\n", ft_lstlast(newlist) -> content);
//    return (0);
// }
