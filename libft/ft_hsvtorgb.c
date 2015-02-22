/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsvtorgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:16:13 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/22 04:28:07 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

int		ft_hsvtorgb(int h, int s, int v)
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
