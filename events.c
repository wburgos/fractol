/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:20:23 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/19 23:26:05 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fractol.h"

int		keys_listener(int keycode, t_env *e)
{
	double		step;

	step = 1 / e->zoom;
	if (keycode == ESC_CODE)
		exit(0);
	if (keycode == LEFT_ARR)
		e->move_x -= step;
	if (keycode == UP_ARR)
		e->move_y -= step;
	if (keycode == RIGHT_ARR)
		e->move_x += step;
	if (keycode == DOWN_ARR)
		e->move_y += step;
	if (keycode == LEFT_ARR || keycode == UP_ARR
		|| keycode == RIGHT_ARR || keycode == DOWN_ARR)
		render_fract(e);
	return (0);
}

int		mouse_listener(int button, int x, int y, t_env *e)
{
	if (button == LEFT_CLICK)
		e->fixed = e->fixed == 0 ? 1 : 0;
	if (button == WHEEL_UP)
		e->zoom += 1;
	if (button == WHEEL_DOWN && e->zoom > 1)
		e->zoom -= 1;
	if ((button == WHEEL_UP || button == WHEEL_DOWN) && e->zoom > 1)
		render_fract(e);
	return (0);
}

int		motion_listener(int x, int y, t_env *e)
{
	if (e->fixed == 0 && e->arg == 1)
	{
		e->const_r = (x - (WIN_WIDTH / 2)) * 0.007 / e->zoom;
		e->const_i = (y - (WIN_HEIGHT / 2)) * 0.007 / e->zoom;
		render_fract(e);
	}
	return (0);
}
