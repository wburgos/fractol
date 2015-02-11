/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:52:54 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 22:34:48 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const t_byte	*p1;
	const t_byte	*p2;
	t_byte			c1;
	t_byte			c2;

	p1 = (const t_byte*)s1;
	p2 = (const t_byte*)s2;
	c1 = (t_byte)*p1;
	c2 = (t_byte)*p2;
	while (c1 != '\0' && (c1 == c2))
	{
		c1 = (t_byte)*p1++;
		c2 = (t_byte)*p2++;
	}
	return (c1 - c2);
}
