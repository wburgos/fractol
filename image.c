/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:12:37 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/16 22:39:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

void	ft_putpix(t_env *e, int x, int y, int color)
{
	char	*toto;
	
	toto = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &(e->endian));
}

