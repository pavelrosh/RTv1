/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:20:34 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/07 18:15:34 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(s1);
	while ((s2[i]) && n > 0)
	{
		s1[len + i] = s2[i];
		i++;
		n--;
	}
	s1[len + i] = '\0';
	return (s1);
}
