/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:04:37 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/15 22:04:37 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	// guardar next em temp
	t_list	*temp;

	if (!lst || !(*del))
		return ;
	temp = lst->next;
	// apagar next
	(*del)(lst->next);
	// colocar a info de next em lst
	lst = temp;
	// delete temp
	(*del)(temp);
}

//    1    2    3    4    5
//        lst  next
//
//      content
//        next