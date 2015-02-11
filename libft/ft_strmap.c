/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:16:05 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 16:19:27 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	if (s)
	{
		ret = ft_strnew(ft_strlen(s));
		if (ret)
			while (*s != '\0')
				ret[i++] = f(*s++);
	}
	return (ret);
}
