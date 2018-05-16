/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:20:24 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:38:48 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*new_str;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((new_str = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
		{
			ft_strcpy(new_str, s1);
			ft_strcat(new_str, s2);
			return (new_str);
		}
	}
	return (NULL);
}
