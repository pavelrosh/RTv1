/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:32:01 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:20:58 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		if_negative(long int n)
{
	return ((n < 0) ? -n : n);
}

static int			str_len(long int n)
{
	int			len;
	long int	n_tmp;

	n_tmp = n;
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (n_tmp < 0)
		return (len + 1);
	else if (n_tmp > 0)
		return (len);
	else
		return (len + 1);
	return (0);
}

static char			ft_nbr(int n)
{
	char c;

	c = '0' + n;
	return (c);
}

char				*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			tmp;
	int			minus;
	long int	n_tmp;

	minus = (n < 0) ? -1 : 1;
	tmp = 0;
	n_tmp = if_negative(n);
	len = str_len(n);
	if ((res = (char *)malloc(sizeof(res) * (len + 1))) != NULL)
	{
		res[len--] = '\0';
		while (len >= 0)
		{
			tmp = n_tmp % 10;
			n_tmp /= 10;
			if (len == 0 && minus == -1)
				res[len--] = '-';
			else
				res[len--] = ft_nbr(tmp);
		}
		return (res);
	}
	return (NULL);
}
