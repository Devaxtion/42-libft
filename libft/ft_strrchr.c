/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:39:01 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/10 14:01:55 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	occured;
	int	last_occurrence;

	i = 0;
	occured = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			last_occurrence = i;
			occured = 1;
			break;
		}
		i++;
	}
	if (occured)
		return ((char *)(s + last_occurrence));

	return (NULL);
}