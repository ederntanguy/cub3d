/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:06 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/14 09:51:36 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	f;
	size_t	b;
	size_t	k;

	f = 0;
	if (size)
		f = ft_strlen(dst);
	k = ft_strlen(src);
	b = 0;
	i = 0;
	while (size > 0 && dst[i])
	{
		i++;
		size--;
	}
	if (size == 0)
		return (k + size + i);
	while (src[b] && b < size - 1)
		dst[i++] = src[b++];
	dst[i] = '\0';
	return (k + f);
}
