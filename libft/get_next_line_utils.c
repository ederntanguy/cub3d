/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:14:10 by ederntanguy       #+#    #+#             */
/*   Updated: 2022/11/22 17:30:44 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isbackslashinbuf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	findbackslash(char *buf, int *res)
{
	int	i;

	i = 0;
	if (res)
		i = *res;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*putthebuffer(char *buf, char *line)
{
	int		i;
	int		j;
	int	k;
	char	*newline;

	j = 0;
	i = -1;
	k = findbackslash(buf, 0);
	if (k == 0)
		k = ft_strlen(buf);
	newline = malloc((k + 1 + ft_strlen(line) + 1) * sizeof(char));
	if (!newline)
		return (free(line), NULL);
	if (line)
		while (line[++i])
			newline[i] = line[i];
	else
		i = 0;
	while (buf[j] && buf[j - 1] != '\n')
		newline[i++] = buf[j++];
	newline[i] = '\0';
	free(line);
	return (newline);
}

char	*toomanylines(char *line, int *res, int ret)
{
	if (line && ret == 0)
	{
		*res = 0;
		if (ft_strlen(line) == 0)
			return (free(line), NULL);
		return (line);
	}
	if (ret == 0 && !(*res))
		return (NULL);
	return (NULL);
}
