/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:54:11 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/08 18:27:36 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const t_byte	*p1;
	const t_byte	*p2;
	t_byte			c1;
	t_byte			c2;

	p1 = (const t_byte*)s1;
	p2 = (const t_byte*)s2;
	while (n-- > 0)
	{
		c1 = *p1++;
		c2 = *p2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
