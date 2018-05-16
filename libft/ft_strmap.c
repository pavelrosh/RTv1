/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:21:15 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/09 13:09:16 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*new_str;
	int		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		new_str = (char *)malloc(sizeof(char) * (len + 1));
		if (new_str != NULL)
		{
			while (s[i])
			{
				new_str[i] = f(s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
		return (new_str);
	}
	return (NULL);
}
