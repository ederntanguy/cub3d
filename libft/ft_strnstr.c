/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:33:06 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/13 17:24:20 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static char	*toomuchline(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (len > i && big[i])
	{
		if (big[i] == little[j])
		{
			k = i - 1;
			while (big[++k] == little[j] && len > k)
				j++;
			if (little[j] == '\0')
				return ((char *)big + k - j);
			j = 0;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if ((!ft_strncmp(big, "", ft_strlen(big))
			&& !ft_strncmp(little, "", ft_strlen(little))))
		return ((char *)big);
	return (toomuchline(big, little, len));
}
/*
int main()
{
	char	l[] = "";
	char	j[] = "";
	char haystack[30] = "aaabcabcd";
	char *empty = (char*)"";
	printf("%s | %s", ft_strnstr(haystack, "abcd", 9), haystack + 5);
	return (0);
}
*/