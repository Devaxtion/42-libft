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
	t_list	*new_lst;
	t_list *temp_lst;
	t_list *temp_new_node;

	if (!lst || !(*f) || !(*del))
		return (NULL);

	
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);

	temp_lst = lst->next;
	while (temp_lst)
	{
		temp_new_node = ft_lstnew((*f)(temp_lst->content));
		if (!temp_new_node)
		{
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp_new_node);
		temp_lst = temp_lst->next;
	}

	return (new_lst);
}
