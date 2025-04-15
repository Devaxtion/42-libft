/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:46:02 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:02 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	num;
	size_t	i;

	if (n == -2147483648)
        return (ft_strdup("-2147483648"));
	len = int_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n < 0)
		num = -num;
	i = len;
	while (i > 0)
	{
		str[--i] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}