/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:44:24 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/17 19:19:26 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	num(const char *str, int i)
{
	unsigned long res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res);
}

static int				tab_runner(const char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	return (i);
}

int						ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;

	res = 0;
	i = 0;
	i = tab_runner(str, i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i - 1] == '-' && (str[i - 2] == '-' || str[i - 2] == '+'))
				return (0);
			else if (str[i - 1] == '-')
				return (num(str, i) * -1);
			if (str[i - 1] == '+' && (str[i - 2] == '-' || str[i - 2] == '+'))
				return (0);
			else
				return (num(str, i));
		}
		else if (str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (res);
}
