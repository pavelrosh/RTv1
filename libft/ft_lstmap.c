/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:18 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:42:45 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *new;
	t_list *tmp;

	if (lst != NULL)
	{
		new = (*f)(lst);
		map = new;
		lst = lst->next;
		while (lst)
		{
			tmp = (*f)(lst);
			map->next = tmp;
			map = tmp;
			lst = lst->next;
		}
		map->next = NULL;
		return (new);
	}
	return (NULL);
}
