/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:43:56 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/14 15:43:56 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	
	array = malloc((ft_countword(s, c) + 1) * sizeof(char *));;
	if (!array)
		return (NULL);
	
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				str_len = ft_strlen(s);
			else
				str_len = ft_strchr(s, c) - s;
			array[i++] = ft_substr(s, 0, str_len);
			s += str_len;
		}
	}
	array[i] = NULL;
	return (array);
}
