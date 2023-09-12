/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:15 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:28:15 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcule_coordonate_chunck(int chunck, int *x, int *y, char **map)
{
	*x = 0;
	*y = 0;
	while (chunck)
	{
		if (chunck >= (ft_strlen(map[*y]) - 1))
		{
			*y += 1;
			chunck -= (ft_strlen(map[(*y) - 1]) - 1);
		}
		else
		{
			*x += chunck;
			chunck = 0;
		}
	}
}

int	count_nb_chunck(char **map)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}
