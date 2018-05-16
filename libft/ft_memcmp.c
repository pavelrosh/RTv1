/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:28:37 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/07 15:22:14 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *new_s1;
	unsigned char *new_s2;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*new_s1 != *new_s2)
			return (*new_s1 - *new_s2);
		else
		{
			new_s1++;
			new_s2++;
		}
	}
	return (0);
}
