/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:09:04 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/09 13:27:03 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*latest = NULL;

	while (*s)
	{
		if (*s == (char)c)
			latest = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)latest);
}
