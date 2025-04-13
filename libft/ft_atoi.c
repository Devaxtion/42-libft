/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:08:31 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/12 12:08:31 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_iswhitespace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
    size_t	i;
    unsigned long	number;
    int	sign;

    i = 0;
    number = 0;
    sign = 1;
    while (ft_iswhitespace(nptr[i]))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(nptr[i]))
    {
        number = (number * 10) + (nptr[i] - '0');
        if (number > INT_MAX && sign == 1)
            return (INT_MAX);
        if (number > (unsigned long)INT_MAX + 1 && sign == -1)
            return (INT_MIN);
        i++;
    }
    return (sign * number);
}
