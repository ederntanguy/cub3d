/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:12:40 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/10 12:35:52 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		n2 = -n;
		write(fd, "-", 1);
	}
	else
		n2 = n;
	if (n2 < 10)
	{
		ft_putchar_fd(n2 + '0', fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
}
/*
int main()
{
	ft_putnbr_fd(2147483647, 1);
}
*/