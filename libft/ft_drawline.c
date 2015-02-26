/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:56:04 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 15:10:15 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_drawline(t_point p1, t_point p2, t_baseenv *e)
{
	int		x;
	int		y;
	t_line	line;

	x = p1.x;
	y = p1.y;
	line.delta_x = p2.x - p1.x;
	line.delta_y = p2.y - p1.y;
	line.error = 0;
	line.delta_error = ft_abs((float)line.delta_y / (float)line.delta_x);
	while (x < p2.x)
	{
		ft_putpix(e->mlx, e->win, x, y, 0xFFFFFF);
		line.error += line.delta_error;
		while (line.error >= 0.5)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
			y += ft_sign(p2.y - p1.y);
			line.error -= 1;
		}
		x++;
	}
}
