/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/11 18:13:14 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

int		is_arg_legit(char *arg)
{
	if (ft_strcmp(arg, "jul") == 0
		|| ft_strcmp(arg, "mand") == 0
		|| ft_strcmp(arg, "3rd") == 0)
		return (1);
	return (0);
}

int		mlx_escape(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		draw_frac(t_env *e)
{
	fractol(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && is_arg_legit(av[1]))
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1280, 800, "Fractol");
		e.arg = av[1];
		mlx_key_hook(e.win, mlx_escape, &e);
		mlx_expose_hook(e.win, draw_frac, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr_fd("available options: [jul; mand; 3rd]\n", 2);
	return (0);
}
