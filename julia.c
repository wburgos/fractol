/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 01:46:28 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 12:09:08 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_env *e)
{
	int			color;
	int			i;

	e->coords.x = 0;
	while (e->coords.x < WIN_WIDTH)
	{
		e->coords.y = 0;
		while (e->coords.y < WIN_HEIGHT)
		{
			e->params.new_r = 1.5 * (e->coords.x - WIN_WIDTH / 2) /
				(0.5 * e->camera.zoom * WIN_WIDTH) + e->camera.move_x;
			e->params.new_i = (e->coords.y - WIN_HEIGHT / 2) /
				(0.5 * e->camera.zoom * WIN_HEIGHT) + e->camera.move_y;
			i = 0;
			while (i < MAX_ITER)
			{
				e->params.old_r = e->params.new_r;
				e->params.old_i = e->params.new_i;
				e->params.new_r = e->params.old_r * e->params.old_r -
					e->params.old_i * e->params.old_i + e->params.const_r;
				e->params.new_i = 2 * e->params.old_r * e->params.old_i +
					e->params.const_i;
				if ((e->params.new_r * e->params.new_r + e->params.new_i *
						e->params.new_i) > 4)
					break ;
				i++;
			}
			ft_putpix(e, e->coords.x, e->coords.y, 0xAF * i);
			e->coords.y++;
		}
		e->coords.x++;
	}
}
