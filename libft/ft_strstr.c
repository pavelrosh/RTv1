/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:46:59 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/08 13:25:34 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dst, const char *src)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	if (src[0] == '\0')
		return ((char *)dst);
	while (dst[i])
	{
		j = i;
		n = 0;
		while (dst[j] == src[n])
		{
			j++;
			n++;
			if (src[n] == '\0')
				return ((char *)&dst[i]);
		}
		i++;
	}
	return (NULL);
}
