/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:36:12 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/16 15:22:10 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !(*del))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, (*del));
		current = next;
	}
	*lst = NULL;
}