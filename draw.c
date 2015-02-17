/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 23:41:06 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 01:24:39 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	draw_julia(t_env *e)
{
	t_params	n;
	t_camera	c;
	t_coords	p;
	int			max_i;
	int			color;
	int			i;

	n.const_r = -0.7;
	n.const_i = 0.27015;
	max_i = 300;
	p.x = 0;
	p.y = 0;
	c.zoom = 1;
	c.move_x = 0;
	c.move_y = 0;
	i = 0;
	while (p.x < WIN_WIDTH)
	{
		while (p.y < WIN_HEIGHT)
		{
			n.new_r = 1.5 * (p.x - WIN_WIDTH / 2) / (0.5 * c.zoom * WIN_WIDTH)
				+ c.move_x;
			n.new_i = (p.y - WIN_HEIGHT / 2) / (0.5 * c.zoom * WIN_HEIGHT)
				+ c.move_x;
			while (i < max_i)
			{
				n.old_r = n.new_r;
				n.old_i = n.new_i;
				n.new_r = n.old_r * n.old_r - n.old_i * n.old_i + n.const_r;
				n.new_i = 2 * n.old_r * n.old_i + n.const_i;
				if ((n.new_r * n.new_r + n.new_i * n.new_i) > 4)
					break ;
				i++;
			}
			ft_putpix(e, p.x, p.y, 0xFFFFFF);
			p.y++;
		}
		p.x++;
	}
}

void	fractol(t_env *e)
{
	if (e->arg == 1)
		draw_julia(e);
}
