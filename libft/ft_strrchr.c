/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:43:27 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 22:27:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*end;

	len = ft_strlen(s);
	end = (char*)s + len;
	while (end >= s)
	{
		if (*end == (char)c)
			return (end);
		end--;
	}
	return (NULL);
}
