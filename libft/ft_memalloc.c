/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:41:33 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/04 14:29:01 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new_mem;

	new_mem = (void *)malloc(size);
	if (new_mem == NULL)
		return (NULL);
	ft_memset(new_mem, 0, size);
	return (new_mem);
}
