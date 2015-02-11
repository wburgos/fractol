/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:17:05 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/11 01:39:53 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (ft_isblank(*start) && start < end)
		start++;
	while (ft_isblank(*end) && end > s)
		end--;
	len = end - start + 1;
	str = ft_strnew(len);
	str = ft_strncpy(str, s, len + 1);
	return (str);
}
