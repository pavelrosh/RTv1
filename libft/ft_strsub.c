/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:49:46 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:37:21 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		i;

	i = 0;
	if (s != NULL)
	{
		if ((sub_str = (char *)malloc(sizeof(char) * ((int)len + 1))) != NULL)
		{
			while (i < (int)len)
			{
				sub_str[i] = s[start];
				i++;
				start++;
			}
			sub_str[i] = '\0';
			return (sub_str);
		}
	}
	return (NULL);
}
