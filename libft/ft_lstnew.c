/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:08:10 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 15:30:24 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *result;

	if ((result = (t_list *)malloc(sizeof(*result))) != NULL)
	{
		if (content == NULL)
		{
			result->content = NULL;
			result->content_size = 0;
		}
		else
		{
			if ((result->content = (void *)malloc(sizeof(content))) != NULL)
			{
				ft_memcpy(result->content, content, content_size);
				result->content_size = content_size;
			}
		}
		result->next = NULL;
		return (result);
	}
	return (NULL);
}
