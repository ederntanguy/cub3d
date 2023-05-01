/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:22:58 by etanguy           #+#    #+#             */
/*   Updated: 2023/02/02 14:21:25 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	freeall(int nbword, char **end)
{
	while (nbword >= 0)
	{
		free(end[nbword]);
		nbword--;
	}
	free(end);
	return (0);
}

static char	*putword(const char *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	creatword(char **end, const char *s, char c, int i)
{
	int	len;
	int	start;
	int	nbword;

	nbword = 0;
	start = 0;
	while (s[++i])
	{
		if (start == 0)
			len = 0;
		if (s[i] == c)
			start = 0;
		if (s[i] != c)
		{
			start = 1;
			len++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				end[nbword] = putword(s, i - len + 1, i + 1);
				if (!end[nbword++])
					freeall(nbword - 1, end);
			}
		}
	}
	return (1);
}

static int	countword(const char *s, char c, int i)
{
	int	start;
	int	nbword;

	start = 0;
	nbword = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (start == 0 && s[i] == c)
		{
			start = 1;
			nbword++;
		}
		else if (s[i] != c)
			start = 0;
		i++;
	}
	if (start == 1)
		return (nbword);
	return (nbword + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**end;
	int		i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	end = malloc((countword(s, c, i) + 1) * sizeof(char *));
	if (!end)
		return (NULL);
	end[countword(s, c, i)] = 0;
	i--;
	if (!creatword(end, s, c, i))
		return (NULL);
	return (end);
}
/*
int	main(int argc, char **argv)
{
	char	**end;
	int		i;
	i = 0;

	(void)argc;
	end = ft_split(argv[1], argv[2][0]);
	while (end[i])
	{
		printf("%s\n", end[i]);
		free(end[i]);
		i++;
	}
	free(end);
	return (0);
}
*/