/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:38 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/11 12:29:07 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	check(char *set, char carac)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == carac)
			return (1);
		i++;
	}
	return (0);
}

static size_t	kvalue(size_t i)
{
	if (i == 0)
		return (0);
	else
		return (i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	m;
	char	*new;

	i = ft_strlen(s1);
	j = 0;
	k = kvalue(i);
	m = 0;
	while (check((char *)set, s1[j]) == 1 && s1[j])
		j++;
	while (check((char *)set, s1[k]) == 1 && k > 0)
		k--;
	if (!s1[j])
		j = 1;
	new = malloc(sizeof(char) * (-j + k + 2));
	if (!new)
		return (0);
	while (j <= k)
		new[m++] = s1[j++];
	new[m] = '\0';
	return (new);
}
/*
int	main(int argc, char **argv)
{
	char *l;
	l = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", l);
	free(l);
	return (0);
}
*/
