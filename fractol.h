/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:54:01 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/16 23:00:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 	1280
# define WIN_HEIGHT 800
# define ESC_CODE	65307	

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*arg;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr_data;
}				t_env;

void	ft_putpix(t_env *e, int x, int y, int color);

#endif
