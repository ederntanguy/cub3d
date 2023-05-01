/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:50:43 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/11 14:14:35 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*creat;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (__SIZE_MAX__ / nmemb > size)
	{
		creat = malloc(nmemb * size);
		if (!creat)
			return (NULL);
	}
	else
		return (NULL);
	ft_bzero(creat, size * nmemb);
	return (creat);
}
