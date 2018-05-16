/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:34:34 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/20 17:57:42 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *nl, size_t len)
{
	size_t nl_len;

	if (*nl == '\0')
		return ((char *)str);
	nl_len = ft_strlen(nl);
	while (*str != '\0' && len-- >= nl_len)
	{
		if (*str == *nl && ft_memcmp(str, nl, nl_len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
