/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 21:49:11 by wburgos           #+#    #+#             */
/*   Updated: 2015/01/18 22:00:35 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_abs(float n)
{
	int		neg;

	neg = (n < 0) ? -1 : 1;
	return (n * neg);
}