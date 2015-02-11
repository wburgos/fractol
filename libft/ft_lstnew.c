/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:06:33 by wburgos           #+#    #+#             */
/*   Updated: 2014/12/02 03:53:43 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	mylist = (t_list*)malloc(sizeof(t_list));
	mylist->content = ft_memalloc(content_size);
	if (!content)
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	else
	{
		mylist->content = ft_memcpy(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	mylist->next = NULL;
	return (mylist);
}
