/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:53:25 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/14 13:53:25 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	
	start = 0;
	end = ft_strlen(s1) - 1;

	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	
	s2 = malloc(end - start + 1 + 1);
	if (!s2)
		return (NULL);

	i = 0;
	while (i + start <= end)
	{
		s2[i] = s1[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
