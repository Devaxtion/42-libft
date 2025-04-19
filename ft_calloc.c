/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:23:52 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/12 12:23:52 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	size_t	i;
	size_t	total_size;

	total_size = nmemb * size;
	array = malloc(total_size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		array[i] = 0;
		i++;
	}
	return array;
}
