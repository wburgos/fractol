/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:30:33 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 13:47:32 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*d1;

	if (*s2 == '\0')
		return ((char*)s1);
	if (n == 0)
		return (NULL);
	d1 = ft_strnew(n);
	d1 = ft_strncpy(d1, s1, n);
	len = ft_strlen(s2);
	while (*d1 != '\0' && n-- > 0)
	{
		if (ft_strncmp(d1, s2, len) == 0)
			return ((char*)s1);
		d1++;
		s1++;
	}
	return (NULL);
}
