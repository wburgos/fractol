/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:54:01 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/19 23:17:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 		400
# define WIN_HEIGHT 	300
# define ESC_CODE		65307
# define LEFT_ARR		65361
# define UP_ARR			65362
# define RIGHT_ARR		65363
# define DOWN_ARR		65364
# define WHEEL_UP		4
# define WHEEL_DOWN		5
# define LEFT_CLICK		1
# define MAX_ITER		16
# define MOTION_MASK	(1L<<6)
# define MOTION_NOTIFY	6

# include <mlx.h>

typedef struct	s_colors
{
	int		color;
	int		ti;
	int		f;
	int		l;
	int		m;
	int		n;
}				t_colors;

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
	double		old_r;
	double		old_i;
	double		new_r;
	double		new_i;
	double		const_r;
	double		const_i;
	int			win_x;
	int			win_y;
	double		zoom;
	double		move_x;
	double		move_y;
	char		fixed;
}				t_env;

void			ft_putpix(t_env *e, int x, int y, int color);
int				render_fract(t_env *e);
int				keys_listener(int keycode, t_env *e);
int				mouse_listener(int button, int x, int y, t_env *e);
int				motion_listener(int x, int y, t_env *e);
int				hsv_to_rgb(int h, int s, int v);

#endif
