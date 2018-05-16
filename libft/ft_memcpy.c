/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:16:07 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:40:44 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *new_dst;
	unsigned char *new_src;

	new_src = (unsigned char *)src;
	new_dst = (unsigned char *)dst;
	while (n > 0)
	{
		*new_dst = *new_src;
		new_dst++;
		new_src++;
		n--;
	}
	return (dst);
}
