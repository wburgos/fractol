/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 11:47:26 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

int		is_arg_legit(char *arg)
{
	if (ft_strcmp(arg, "jul") == 0)
		return (1);
	if (ft_strcmp(arg, "mand") == 0)
		return (2);
	if (ft_strcmp(arg, "3rd") == 0)
		return (3);
	return (0);
}

int		render_fract(t_env *e)
{
	ft_bzero(e->data, (WIN_HEIGHT * e->size_line) +
		(WIN_WIDTH + (e->bpp >> 3)));
	if (e->arg == 1)
		draw_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

t_env	init_params(t_env e)
{
	if (e.arg == 1)
	{
		e.camera.zoom = 1;
		e.camera.move_x = 0;
		e.camera.move_y = 0;
		e.params.const_r = -0.7;
		e.params.const_i = 0.27015;
	}
	return (e);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && (e.arg = is_arg_legit(av[1])) != 0)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
		e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
		e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line),
			&(e.endian));
		e = init_params(e);
		mlx_key_hook(e.win, keys_listener, &e);
		mlx_expose_hook(e.win, render_fract, &e);
		mlx_mouse_hook(e.win, mouse_listener, &e);
		mlx_hook(e.win, MOTION_NOTIFY, MOTION_MASK, motion_listener, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr_fd("Available options: [jul; mand; 3rd]\n", 2);
	return (0);
}
