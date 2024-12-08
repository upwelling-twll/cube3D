/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:42:31 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 16:37:15 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
	{
		*lst = new;
	}
}

// int main(int argc, char *argv[])
// {
//    //t_list *newlist;
//    t_list	*l =  NULL;
//
// 	t_list	*n = ft_lstnew(strdup("OK"));
// 	ft_lstadd_back(&l, n);

// //    newlist = ft_lstnew(argv[1]);
// //    newlist -> next = ft_lstnew(argv[2]);
// //    newlist -> next -> next = ft_lstnew(argv[3]);
// //    newlist -> next -> next -> next = ft_lstnew(argv[4]);
// //    printf("%s\n", ft_lstlast(newlist) -> content);
//    return (0);
// }
