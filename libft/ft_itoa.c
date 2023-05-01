/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:49:21 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/10 15:26:59 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	putinchar(char *returnvalue, unsigned int i, int len, int neg)
{
	int	j;
	int	div;
	int	k;

	j = 0;
	div = 1;
	if (neg == 1)
	{
		returnvalue[j] = '-';
		j++;
	}
	k = j - 1;
	while (++k < len - 1)
		div *= 10;
	while (j < len)
	{
		returnvalue[j++] = i / div + '0';
		i %= div;
		div /= 10;
	}
	returnvalue[j] = '\0';
	return (1);
}

static int	lennum(int len, unsigned int i)
{
	if (i == 0)
		len = 1;
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*returnvalue;
	unsigned int		i;
	int					len;
	int					neg;

	len = 0;
	neg = 0;
	if (n < 0)
	{
		i = -n;
		len++;
		neg = 1;
	}
	else
		i = n;
	len = lennum(len, i);
	returnvalue = malloc((len + 1) * sizeof(char));
	if (!returnvalue)
		return (0);
	putinchar(returnvalue, i, len, neg);
	return (returnvalue);
}
