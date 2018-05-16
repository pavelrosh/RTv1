/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:36:06 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:41:31 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	new_c;
	unsigned char	*new_dst;
	unsigned char	*new_src;
	int				i;

	i = 0;
	new_src = (unsigned char *)src;
	new_dst = (unsigned char *)dst;
	new_c = (unsigned char)c;
	while ((int)n > i)
	{
		new_dst[i] = new_src[i];
		if (new_src[i] == new_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
