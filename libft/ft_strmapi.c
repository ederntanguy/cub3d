/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:47:12 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/13 17:24:39 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*end;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s);
	end = malloc((len + 1) * sizeof(char));
	if (!end)
		return (end);
	while (s[++i])
		end[i] = f(i, s[i]);
	end[i] = '\0';
	return (end);
}
