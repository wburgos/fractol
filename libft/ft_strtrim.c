/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:17:05 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/20 16:03:42 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_isblank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	const char	*start;
	const char	*end;
	char		*str;
	size_t		len;

	start = s;
	end = s + ft_strlen(s) - 1;
	while (*start && ft_isblank(*start))
		start++;
	if (!*start)
		return (ft_strnew(0));
	while (ft_isblank(*end) && end > s)
		end--;
	len = end - start + 1;
	str = ft_strnew(len);
	str = ft_strncpy(str, start, len);
	return (str);
}
