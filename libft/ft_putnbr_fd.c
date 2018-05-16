/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:47:35 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/14 17:41:01 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -2147483648 || n > 2147483647)
		return ;
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd(((n % 10) + 48), fd);
		return ;
	}
	ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd(((n % 10) + 48), fd);
	return ;
}
