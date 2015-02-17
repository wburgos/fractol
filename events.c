/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:20:23 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 11:41:21 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

int		keys_listener(int keycode, t_env *e)
{
	double		step;

	step = 1 / e->camera.zoom;
	if (keycode == ESC_CODE)
		exit(0);
	if (keycode == LEFT_ARR)
		e->camera.move_x -= step;
	if (keycode == UP_ARR)
		e->camera.move_y -= step;
	if (keycode == RIGHT_ARR)
		e->camera.move_x += step;
	if (keycode == DOWN_ARR)
		e->camera.move_y += step;
	if (keycode == LEFT_ARR || keycode == UP_ARR
		|| keycode == RIGHT_ARR || keycode == DOWN_ARR)
		render_fract(e);
	return (0);
}

int		mouse_listener(int button, int x, int y, t_env *e)
{
	if (button == WHEEL_UP)
		e->camera.zoom += 1;
	if (button == WHEEL_DOWN)
		e->camera.zoom -= 1;
	if (button == WHEEL_UP || button == WHEEL_DOWN)
		render_fract(e);
	return (0);
}

int		motion_listener(int x, int y, t_env *e)
{
	// (e->params).const_r = -0.7;
	// (e->params).const_i = 0.27016;
	// render_fract(e);
	return (0);
}
