/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:13:23 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/11 10:29:30 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, int start, int len)
{
	int	i;
	int	endlen;
	char	*end;

	if (start >= ft_strlen(s))
		endlen = 0;
	else
		endlen = ft_min(ft_strlen(s) - start, len);
	i = 0;
	end = malloc((endlen + 1) * sizeof(char));
	if (!end)
		return (NULL);
	while (i < endlen)
	{
		end[i] = s[start];
		i++;
		start++;
	}
	end[i] = '\0';
	return (end);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *str;
	char *s;

	//str = ft_strdup("0123456789");
	s = ft_substr("tripouille", 1, 1);
	printf("d%dd\n", strcmp(s, "r"));
	return (0);
}
*/