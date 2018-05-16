/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:04:10 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/15 19:22:09 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;
	int		len;

	new_s = (char *)s;
	len = 0;
	while (new_s[len])
		len++;
	while (len >= 0)
	{
		if (*new_s == c)
			return (new_s);
		new_s++;
		len--;
	}
	return (NULL);
}
