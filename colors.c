/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:45:53 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/20 13:22:45 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int		get_from_palette(int val, int max_val)
{
	int		start_color;
	int		augment;
	t_color color;

	start_color = 0x000055;
	augment = round(255 * (round(val * 100 / max_val) / 100));
	color.r = (start_color >> 16) + augment;
	color.g = ((start_color >> 8) & 0xFF) + augment;
	color.b = (start_color & 0xFF) + augment;
	color.val = (color.r << 16) + (color.g << 8) + color.b;
	return (color.val);
}
