/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 22:16:23 by wburgos           #+#    #+#             */
/*   Updated: 2015/01/18 22:17:48 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sign(int n)
{
	if (n < 0)
		return (-1);
	if (n > 0)
		return (1);
	return (0);
}