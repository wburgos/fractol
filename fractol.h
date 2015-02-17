/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:54:01 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/17 01:22:30 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 	1280
# define WIN_HEIGHT 800
# define ESC_CODE	65307

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			arg;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		*addr_data;
}				t_env;

typedef struct	s_params
{
	double		old_r;
	double		old_i;
	double		new_r;
	double		new_i;
	double		const_r;
	double		const_i;
}				t_params;

typedef struct	s_camera
{
	double		zoom;
	double		move_x;
	double		move_y;
}				t_camera;

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

void			ft_putpix(t_env *e, int x, int y, int color);

#endif
