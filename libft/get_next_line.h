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
	int		ret;
}	t_all_variable;

int		isbackslashinbuf(char *buf);
int		findbackslash(char *buf, int *res);
char	*putthebuffer(char *buf, char *line);
char	*putalltheline(char *buf, int *res);
char	*putalltheline2(char *buf, int *res);
char	*get_next_line(int fd);
char	*toomanylines(char *line, int *res, int ret);
void	toomanylines2(char *buf, char **line, int *ret, int fd);
void	toomanylines3(t_all_variable *all, int *res, char **line, int fd);

#endif