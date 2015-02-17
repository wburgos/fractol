/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 01:20:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
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

int		mlx_keys(int keycode, t_env *e)
{
	if (keycode == ESC_CODE)
		exit(0);
	return (0);
}

int		draw_frac(t_env *e)
{
	ft_bzero(e->data, (WIN_HEIGHT * e->size_line) +
			(WIN_WIDTH + (e->bpp >> 3)));
	fractol(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
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
		mlx_key_hook(e.win, mlx_keys, &e);
		mlx_expose_hook(e.win, draw_frac, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr_fd("Available options: [jul; mand; 3rd]\n", 2);
	return (0);
}
