/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:43:24 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/15 18:28:11 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < (int)len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
