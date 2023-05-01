/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:19:37 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/21 15:01:28 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*putalltheline2(char *buf, ssize_t *res)
{
	ssize_t	i;
	char	*line;

	i = *res;
	while (buf[*res])
		*res += 1;
	line = malloc(sizeof(char) * (*res - i + 1));
	if (!line)
		return (NULL);
	*res = i;
	i = 0;
	while (buf[*res])
	{
		line[i++] = buf[*res];
		*res += 1;
	}
	line[i] = '\0';
	return (line);
}

char	*putalltheline(char *buf, ssize_t *res)
{
	ssize_t	i;
	ssize_t	j;
	char	*line;

	i = *res;
	j = findbackslash(buf, res);
	if (j == 0 || *res == j)
		return (putalltheline2(buf, res));
	while (buf[*res] && *res < j)
		*res += 1;
	line = malloc(sizeof(char) * (*res - i + 1));
	if (!line)
		return (NULL);
	*res = i;
	i = 0;
	while (buf[*res] && *res < j)
	{
		line[i++] = buf[*res];
		*res += 1;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_all_variable	all;
	static ssize_t			res = 0;

	all.line = NULL;
	if (res > 0)
	{
		all.line = putalltheline(all.buf, &res);
		if (!(all.line) || findbackslash(all.line, 0))
			return (all.line);
	}
	res = 0;
	all.ret = read(fd, all.buf, BUFFER_SIZE);
	if (all.ret < 0)
		return (free(all.line), NULL);
	(all.buf)[all.ret] = 0;
	if ((all.line && all.ret == 0) || (all.ret == 0 && !res))
		return (toomanylines(all.line, &res, all.ret));
	if (isbackslashinbuf(all.buf))
	{
		all.line = putthebuffer(all.buf, all.line);
		res = findbackslash(all.buf, 0);
	}
	else
		toomanylines3(&all, &res, &(all.line), fd);
	return (all.line);
}

void	toomanylines3(t_all_variable *all, ssize_t *res, char **line, int fd)
{
	*line = putthebuffer(all->buf, *line);
	while (*line && !isbackslashinbuf(all->buf) && all->ret)
		toomanylines2(all->buf, line, &(all->ret), fd);
	if (all->ret)
		*res = findbackslash(all->buf, 0);
	if (!(all->ret))
		*res = 0;
	if (all->buf[0] == '\n' && ft_strlen(all->buf) == 2)
		*res = 1;
}

void	toomanylines2(char *buf, char **line, ssize_t *ret, int fd)
{
	*ret = read(fd, buf, BUFFER_SIZE);
	buf[*ret] = '\0';
	*line = putthebuffer(buf, *line);
}
