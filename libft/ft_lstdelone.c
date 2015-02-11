/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:05:46 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 12:44:11 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	void	*data;
	size_t	dsize;

	if (alst && *alst)
	{
		data = (*alst)->content;
		dsize = (*alst)->content_size;
		del(data, dsize);
		free(*alst);
		alst = NULL;
	}
}
