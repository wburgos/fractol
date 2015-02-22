/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:45:53 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/22 05:00:09 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int		get_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int		hsv_to_rgb(double hue, double saturation, double value)
{
    int hi = ((int)floor(hue / 60)) % 6;
    double f = hue / 60 - floor(hue / 60);

    value = value * 255;
    int v = (int)value;
    int p = (int)value * (1 - saturation);
    int q = (int)value * (1 - f * saturation);
    int t = (int)value * (1 - (1 - f) * saturation);

    if (hi == 0)
        return (get_rgb(v, t, p));
    else if (hi == 1)
        return (get_rgb(q, v, p));
    else if (hi == 2)
        return (get_rgb(p, v, t));
    else if (hi == 3)
        return (get_rgb(p, q, v));
    else if (hi == 4)
        return (get_rgb(t, p, v));
    else
        return (get_rgb(v, p, q));
}

int		pix_color(int i, double r, double c)
{
	double		di;
	double		zn;
	double		hue;

	di = (double)i;
	zn = sqrt(r + c);
	hue = di - log(log(fabs(zn))) / log(2);
	hue = hue * 5;
	while (hue > 360.0)
		hue -= 360.0;
	while (hue < 0.0)
		hue += 360.0;
	return (hsv_to_rgb(hue, 0.8, 1.0));
}
