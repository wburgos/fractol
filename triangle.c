/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:54:23 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 18:17:10 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_tri	get_subtri1(t_tri base)
{
	t_tri	res;

	res.p1.x = (base.p1.x + base.p2.x) / 2 + (base.p2.x - base.p3.x) / 2;
	res.p1.y = (base.p1.y + base.p2.y) / 2 + (base.p2.y - base.p3.y) / 2;
	res.p2.x = (base.p1.x + base.p2.x) / 2 + (base.p1.x - base.p3.x) / 2;
	res.p2.y = (base.p1.y + base.p2.y) / 2 + (base.p1.y - base.p3.y) / 2;
	res.p3.x = (base.p1.x + base.p2.x) / 2;
	res.p3.y = (base.p1.y + base.p2.y) / 2;
	return (res);
}

t_tri	get_subtri2(t_tri base)
{
	t_tri	res;

	res.p1.x = (base.p3.x + base.p2.x) / 2 + (base.p2.x - base.p1.x) / 2;
	res.p1.y = (base.p3.y + base.p2.y) / 2 + (base.p2.y - base.p1.y) / 2;
	res.p2.x = (base.p3.x + base.p2.x) / 2 + (base.p3.x - base.p1.x) / 2;
	res.p2.y = (base.p3.y + base.p2.y) / 2 + (base.p3.y - base.p1.y) / 2;
	res.p3.x = (base.p3.x + base.p2.x) / 2;
	res.p3.y = (base.p3.y + base.p2.y) / 2;
	return (res);
}

t_tri	get_subtri3(t_tri base)
{
	t_tri	res;

	res.p1.x = (base.p1.x + base.p3.x) / 2 + (base.p3.x - base.p2.x) / 2;
	res.p1.y = (base.p1.y + base.p3.y) / 2 + (base.p3.y - base.p2.y) / 2;
	res.p2.x = (base.p1.x + base.p3.x) / 2 + (base.p1.x - base.p2.x) / 2;
	res.p2.y = (base.p1.y + base.p3.y) / 2 + (base.p1.y - base.p2.y) / 2;
	res.p3.x = (base.p1.x + base.p3.x) / 2;
	res.p3.y = (base.p1.y + base.p3.y) / 2;
	return (res);
}

void	subtriangle(int n, t_tri tri, t_env *e)
{
	ft_drawline(tri.p1, tri.p2, e);
	ft_drawline(tri.p1, tri.p3, e);
	ft_drawline(tri.p3, tri.p2, e);
	if (n < e->depth)
	{
		subtriangle(n + 1, get_subtri1(tri), e);
		subtriangle(n + 1, get_subtri2(tri), e);
		subtriangle(n + 1, get_subtri3(tri), e);
	}
}

void	render_triforce(t_env *e)
{
	t_tri	tri;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	tri.p1.x = 10 - e->zoom - e->move_x;
	tri.p1.y = WIN_HEIGHT - 10 + e->zoom - e->move_y;
	tri.p2.x = WIN_WIDTH - 10 + e->zoom - e->move_x;
	tri.p2.y = WIN_HEIGHT - 10 + e->zoom - e->move_y;
	tri.p3.x = WIN_WIDTH / 2 - e->move_x;
	tri.p3.y = 10 - e->zoom - e->move_y;
	ft_drawline(tri.p1, tri.p2, e);
	ft_drawline(tri.p1, tri.p3, e);
	ft_drawline(tri.p3, tri.p2, e);
	p1.x = (tri.p1.x + tri.p2.x) / 2;
	p1.y = (tri.p1.y + tri.p2.y) / 2;
	p2.x = (tri.p1.x + tri.p3.x) / 2;
	p2.y = (tri.p1.y + tri.p3.y) / 2;
	p3.x = (tri.p2.x + tri.p3.x) / 2;
	p3.y = (tri.p2.y + tri.p3.y) / 2;
	tri.p1 = p1;
	tri.p2 = p2;
	tri.p3 = p3;
	subtriangle(1, tri, e);
}
