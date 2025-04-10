/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:18:16 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/10 13:33:05 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;
	int	src_size;
	int	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < (size - dst_size - 1))
		{
			dst[dst_size + i] = src[i];
			i++;
		}
	}
	return (src_size + dst_size);
}
