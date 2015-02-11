/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:54:19 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 20:48:32 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_byte	*dst2;
	t_byte	*src2;
	t_byte	c2;

	dst2 = (t_byte*)dst;
	src2 = (t_byte*)src;
	c2 = (t_byte)c;
	while (n-- > 0)
	{
		*dst2 = *src2++;
		if (*dst2++ == c2)
			return (dst2);
	}
	return (NULL);
}
