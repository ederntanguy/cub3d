/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:27:20 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/11 14:37:20 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*end;

	i = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	end = malloc((i + 1) * sizeof(char));
	if (!end)
		return (NULL);
	i = 0;
	while (s1[j])
	{
		end[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		end[i] = s2[j];
		i++;
		j++;
	}
	end[i] = '\0';
	return (end);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}
*/