/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:06:48 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:41:53 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_src;
	unsigned char	*new_dst;
	int				i;

	i = -1;
	new_src = (unsigned char *)src;
	new_dst = (unsigned char *)dest;
	if (new_src < new_dst)
		while ((int)(--n) >= 0)
			*(new_dst + n) = *(new_src + n);
	else
		while (++i < (int)n)
			*(new_dst + i) = *(new_src + i);
	return (dest);
}
