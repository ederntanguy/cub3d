/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:35 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/21 15:01:16 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct all_variable
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		ret;
}	t_all_variable;

ssize_t	isbackslashinbuf(char *buf);
ssize_t	findbackslash(char *buf, ssize_t *res);
char	*putthebuffer(char *buf, char *line);
char	*putalltheline(char *buf, ssize_t *res);
char	*putalltheline2(char *buf, ssize_t *res);
char	*get_next_line(int fd);
char	*toomanylines(char *line, ssize_t *res, ssize_t ret);
void	toomanylines2(char *buf, char **line, ssize_t *ret, int fd);
void	toomanylines3(t_all_variable *all, ssize_t *res, char **line, int fd);

#endif