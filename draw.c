/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 01:46:28 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/20 01:37:43 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_env_values(t_env *e, double *re, double *im)
{
	double		r;
	double		i;

	r = 1.5 * (e->win_x - WIN_WIDTH / 2) / (0.5 * e->zoom * WIN_WIDTH) +
		e->move_x;
	i = (e->win_y - WIN_HEIGHT / 2) / (0.5 * e->zoom * WIN_HEIGHT) + e->move_y;
	if (e->arg == 1)
	{
		e->new_r = r;
		e->new_i = i;
		*re = e->const_r;
		*im = e->const_i;
	}
	if (e->arg == 2)
	{
		*re = r;
		*im = i;
		e->new_r = 0;
		e->new_i = 0;
		e->old_r = 0;
		e->old_i = 0;
	}
}

int		do_iter(t_env *e, double re, double im)
{
	int		i;

	i = 0;
	while (i < e->max_i)
	{
		e->old_r = e->new_r;
		e->old_i = e->new_i;
		e->new_r = e->old_r * e->old_r - e->old_i * e->old_i + re;
		e->new_i = 2 * e->old_r * e->old_i + im;
		if ((e->new_r * e->new_r + e->new_i * e->new_i) > 4)
			return (i);
		i++;
	}
	return (i);
}

void	draw_fract(t_env *e)
{
	int			i;
	double		r;
	double		im;
	int			color;

	e->win_x = 0;
	while (e->win_x < WIN_WIDTH)
	{
		e->win_y = 0;
		while (e->win_y < WIN_HEIGHT)
		{
			set_env_values(e, &r, &im);
			i = do_iter(e, r, im);
			ft_putpix(e, e->win_x, e->win_y, hsv_to_rgb(i % 360, i % 101,
				i % 101));
			e->win_y++;
		}
		e->win_x++;
	}
}
