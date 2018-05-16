/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:10:50 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/14 17:00:46 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		if ((new_str = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
		{
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			len--;
			while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
				len--;
			if (i > len)
				return (ft_strdup(""));
			new_str = ft_strsub(s, i, ((len + 1) - i));
			return (new_str);
		}
	}
	return (NULL);
}
