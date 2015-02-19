/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:45:53 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/19 23:20:10 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int		hsv_to_rgb(int h, int s, int v)
{
	t_colors	c;

	c.color = 0;
	c.ti = (int)floor(h / 60) % 6;
	c.f = h / 60 - (double)c.ti;
	c.l = v * (1 - s);
	c.m = v * (1 - c.f * s);
	c.n = v * (1 - (1 - c.f) * s);
	c.color = (c.ti == 0) ? ((v << 16) + (c.n << 8) + (c.l)) : c.color;
	c.color = (c.ti == 1) ? ((c.m << 16) + (v << 8) + (c.l)) : c.color;
	c.color = (c.ti == 2) ? ((c.l << 16) + (v << 8) + (c.n)) : c.color;
	c.color = (c.ti == 3) ? ((c.l << 16) + (c.m << 8) + (v)) : c.color;
	c.color = (c.ti == 4) ? ((c.n << 16) + (c.l << 8) + (v)) : c.color;
	c.color = (c.ti == 5) ? ((v << 16) + (c.n << 8) + (c.m)) : c.color;
	return (c.color);
}
