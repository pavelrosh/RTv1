/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:19:04 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/15 19:22:26 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;
	char	find_c;
	int		len;

	len = 0;
	new_s = (char *)s;
	find_c = (char)c;
	while (new_s[len])
		len++;
	while (len >= 0)
	{
		if (new_s[len] == find_c)
			return (&new_s[len]);
		len--;
	}
	return (NULL);
}
