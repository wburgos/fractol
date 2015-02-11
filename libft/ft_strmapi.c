/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:16:17 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 16:22:05 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = NULL;
	if (s)
	{
		ret = ft_strnew(ft_strlen(s));
		if (ret)
		{
			while (s[i] != '\0')
			{
				ret[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (ret);
}
