/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:07:10 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 22:33:56 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*p1;
	const char	*p2;

	p2 = s2;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		if (*s1 != *p2)
		{
			s1++;
			continue ;
		}
		p1 = s1;
		while (*p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return ((char*)s1);
		p2 = s2;
		s1++;
	}
	return (NULL);
}
