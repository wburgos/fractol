/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:01:33 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 12:45:25 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmodcpy(t_list **prev, t_list *mod)
{
	t_list	*cpy;

	cpy = ft_lstnew(mod->content, mod->content_size);
	if (prev)
		(*prev)->next = cpy;
	else
		*prev = cpy;
	return (cpy);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*elem;
	t_list	*tmp;
	int		first;

	tmp = lst;
	first = 1;
	if (tmp)
	{
		while (tmp->next)
		{
			if (first)
			{
				ft_lstmodcpy(&begin_list, f(tmp));
				elem = begin_list;
				first = 0;
			}
			else
				elem = ft_lstmodcpy(&elem, f(tmp));
			tmp = tmp->next;
		}
		return (begin_list);
	}
	return (NULL);
}
