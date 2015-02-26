/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:20:23 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 18:13:11 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fractol.h"

void	reset_camera(t_env *e)
{
	e->zoom = 1;
	e->move_x = e->arg == 1 ? 0 : -1;
	e->move_y = 0;
	e->max_i = e->arg == 1 ? 16 : 116;
	e->depth = 6;
}

int		needs_rerender(int keycode)
{
	if (keycode == LEFT_ARR
		|| keycode == UP_ARR
		|| keycode == RIGHT_ARR
		|| keycode == DOWN_ARR
		|| keycode == ZERO_KEY
		|| keycode == PLUS_KEY
		|| keycode == MINUS_KEY)
		return (1);
	return (0);
}

int		keys_listener(int keycode, t_env *e)
{
	double		step;

	step = (e->arg == 3) ? 20 : 0.3 / e->zoom;
	if (keycode == SPACEBAR)
		e->fixed = e->fixed == 0 ? 1 : 0;
	if (keycode == ZERO_KEY)
		reset_camera(e);
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
	if (keycode == PLUS_KEY)
		(e->arg == 3) ? (e->depth += 1) : (e->max_i += 4);
	if (keycode == MINUS_KEY && e->max_i > 16)
		(e->arg == 3) ? (e->depth -= 1) : (e->max_i -= 4);
	if (needs_rerender(keycode))
		render_fract(e);
	return (0);
}

int		mouse_listener(int button, int x, int y, t_env *e)
{
	if (button == WHEEL_UP)
		e->zoom *= 1.1;
	if (button == WHEEL_DOWN && e->zoom > 1)
		e->zoom /= 1.1;
	if (button == WHEEL_UP || (button == WHEEL_DOWN && e->zoom > 1))
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
