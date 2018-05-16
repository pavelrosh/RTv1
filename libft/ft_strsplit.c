/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:12:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:35:16 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_numb(const char *s, char c)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c)
			{
				if (s[i] == '\0')
					return (++res);
				else
					i++;
			}
			res++;
		}
	}
	return (res);
}

static int			word(const char *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int			return_counter(const char *s, char c, int j, int count)
{
	int i;

	i = 0;
	if (word_numb(s, c) >= j)
		return (i += count);
	else
		i++;
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	if (s && (res = (char**)malloc(sizeof(res) * (word_numb(s, c) + 1))))
	{
		while (s[i])
		{
			if (s[i] == c)
				i++;
			else
			{
				count = word(s, i, c);
				res[j++] = ft_strsub(s, i, count);
				i += return_counter(s, c, j, count);
			}
		}
		res[j] = NULL;
		return (res);
	}
	return (NULL);
}
