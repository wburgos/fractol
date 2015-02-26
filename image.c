/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:12:37 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 17:54:17 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"

void	ft_putpix(t_env *e, int x, int y, int color)
{
	int		index;

	index = (y * e->size_line) + (x * (e->bpp >> 3));
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		e->data[index] = color & 0xff;
		e->data[index + 1] = (color & 0xff00) >> 8;
		e->data[index + 2] = (color & 0xff0000) >> 16;
		e->data[index + 3] = 0;
	}
}

void	swap_points(t_point *p1, t_point *p2)
{
	float	tx;
	float	ty;

	tx = p1->x;
	ty = p1->y;
	if (tx > p2->x)
	{
		p1->x = p2->x;
		p1->y = p2->y;
		p2->x = tx;
		p2->y = ty;
	}
}

void	ft_drawline(t_point p1, t_point p2, t_env *e)
{
	float	x;
	float	y;
	t_line	line;

	if (p1.x > p2.x)
		swap_points(&p1, &p2);
	x = p1.x;
	y = p1.y;
	line.delta_x = p2.x - p1.x;
	line.delta_y = p2.y - p1.y;
	line.error = 0;
	line.delta_error = ft_abs(line.delta_y / line.delta_x);
	while (x < p2.x)
	{
		ft_putpix(e, x, y, 0xFFFFFF);
		line.error += line.delta_error;
		while (line.error >= 0.5)
		{
			ft_putpix(e, x, y, 0xFFFFFF);
			y += ft_sign(p2.y - p1.y);
			line.error -= 1;
		}
		x++;
	}
}
