/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:05:45 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/07 15:14:33 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char new_c;
	unsigned char *new_str;

	new_str = (unsigned char *)s;
	new_c = (unsigned char)c;
	while (n > 0)
	{
		if (*new_str == new_c)
			return (new_str);
		new_str++;
		n--;
	}
	return (NULL);
}
