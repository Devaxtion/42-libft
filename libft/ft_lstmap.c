/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:44:30 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/16 13:01:56 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	// new = malloc(sizeof(t_list));
	// if (!new)
	// 	return (NULL);
	// new->content = (*f)(lst->content);

	new = ft_lstnew((*f)(lst->content));
	if (!new)
	{
		ft_lstclear(&new, (*del));
		return (NULL);
	}

	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->next->content));
		lst = lst->next;
	}
	return (new);
}