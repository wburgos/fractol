/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:45:53 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/19 15:14:26 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		hsv_to_rgb(int h, int s, int v)
{
	int		color;
	int		ti;
	int		f;
	int		l;
	int		m;
	int		n;

	color = 0;
	ti = (int)floor(h/60)%6;
	f = h/60 - (double)ti;
	l = v * (1 - s);
	m = v * (1 - f * s);
	n = v * (1 - (1 - f) * s);
	color = (ti == 0) ? ((v << 16) + (n << 8) + (l)) : color;
	color = (ti == 1) ? ((m << 16) + (v << 8) + (l)) : color;
	color = (ti == 2) ? ((l << 16) + (v << 8) + (n)) : color;
	color = (ti == 3) ? ((l << 16) + (m << 8) + (v)) : color;
	color = (ti == 4) ? ((n << 16) + (l << 8) + (v)) : color;
	color = (ti == 5) ? ((v << 16) + (n << 8) + (m)) : color;
	return (color);
}
