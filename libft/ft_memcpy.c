/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:52:37 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 12:40:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte			*dst2;
	const t_byte	*src2;

	dst2 = (t_byte*)dst;
	src2 = (t_byte*)src;
	while (n-- > 0)
		*dst2++ = *src2++;
	return (dst);
}
