/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:23:51 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/10 16:41:17 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d2;
	const char	*s2;
	size_t		n;
	size_t		dlen;

	d2 = dst;
	s2 = src;
	n = size;
	while (*d2 != '\0' && n-- > 0)
		d2++;
	dlen = d2 - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s2));
	while (*s2 != '\0')
	{
		if (n != 1)
		{
			*d2++ = *s2;
			n--;
		}
		s2++;
	}
	*d2 = '\0';
	return (dlen + (s2 - src));
}
