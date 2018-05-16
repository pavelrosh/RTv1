/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:09:45 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/09 13:18:10 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;
	int		len;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		new_s = (char *)malloc(sizeof(char) * (len + 1));
		if (new_s != NULL)
		{
			while (s[i])
			{
				new_s[i] = f(i, s[i]);
				i++;
			}
			new_s[i] = '\0';
			return (new_s);
		}
	}
	return (NULL);
}
