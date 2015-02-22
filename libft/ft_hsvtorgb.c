/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsvtorgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:16:13 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/22 05:15:07 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

int		ft_hsvtorgb(double hue, double saturation, double value)
{
	t_color		c;

	c.hi = ((int)floor(hue / 60)) % 6;
	c.f = hue / 60 - floor(hue / 60);
	value = value * 255;
	c.v = (int)value;
	c.p = (int)value * (1 - saturation);
	c.q = (int)value * (1 - c.f * saturation);
	c.t = (int)value * (1 - (1 - c.f) * saturation);
	if (c.hi == 0)
		return (ft_getcolor(c.v, c.t, c.p));
	else if (c.hi == 1)
		return (ft_getcolor(c.q, c.v, c.p));
	else if (c.hi == 2)
		return (ft_getcolor(c.p, c.v, c.t));
	else if (c.hi == 3)
		return (ft_getcolor(c.p, c.q, c.v));
	else if (c.hi == 4)
		return (ft_getcolor(c.t, c.p, c.v));
	else
		return (ft_getcolor(c.v, c.p, c.q));
}
