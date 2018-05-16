/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:37:17 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:42:03 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char new_c;
	unsigned char *new_b;

	new_c = (unsigned char)c;
	new_b = (unsigned char *)b;
	while (len > 0)
	{
		*new_b = new_c;
		new_b++;
		len--;
	}
	return (b);
}
