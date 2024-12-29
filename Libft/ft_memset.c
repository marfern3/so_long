/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofernandezcallejon <marcofernandezc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:06:19 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/09 22:09:47 by marcofernan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s2;
	char	c2;
	size_t	i;

	s2 = (char *)s;
	c2 = (char)c;
	i = 0;
	while (i < n)
	{
		s2[i] = c2;
		i++;
	}
	return (s2);
}
