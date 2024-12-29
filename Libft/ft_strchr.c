/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:07:10 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/09 10:07:14 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)&s[i]);
		i++;
	}
	if (c2 == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
