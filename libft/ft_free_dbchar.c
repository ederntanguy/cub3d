/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:12 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:40:16 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_free_dbchar_tab(char **str, int size)
{
	int	i;

	i = size;
	if (i == 0)
		i = ft_dbstrlen(str) - 1;
	while (i >= 0 && str[i])
		free(str[i--]);
	free(str);
	str = NULL;
	return (0);
}
