/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:02:52 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/09 10:02:54 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isnegative(int n, int len)
{
	char	*str;

	str = ft_calloc(len + 1, sizeof (char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(str, "-2147483648", 12));
	n *= -1;
	while (len > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

static int	intlen(int n)
{
	int			i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	len = intlen(n);
	if (n < 0)
		return (ft_isnegative(n, len));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
