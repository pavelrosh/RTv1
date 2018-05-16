/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:01:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/15 18:27:46 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*copy_str;
	int		dst_len;
	int		src_len;
	int		counter;
	int		res;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	counter = (int)dstsize - dst_len - 1;
	res = ft_strlen(dst) + ft_strlen(src);
	if ((int)dstsize <= dst_len)
		return (src_len + (int)dstsize);
	else
	{
		copy_str = ft_strncat(dst, src, counter);
		return (res);
	}
	return (res);
}
