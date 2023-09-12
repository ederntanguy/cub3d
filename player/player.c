/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:01:15 by gde-carv          #+#    #+#             */
/*   Updated: 2023/09/12 11:31:04 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_rotation_player(char orientation)
{
	if (orientation == 'N')
		return (270);
	else if (orientation == 'E')
		return (0);
	else if (orientation == 'S')
		return (90);
	else if (orientation == 'W')
		return (180);
	return (0);
}

t_player	make_player(char **map)
{
	t_player		player;
	t_coordonate	chunck_pos;
	int				chuck;

	chuck = 0;
	chunck_pos.y = 0;
	while (map[chunck_pos.y])
	{
		calcule_coordonate_chunck(chuck, &(chunck_pos.x), &(chunck_pos.y), map);
		if (map[chunck_pos.y][chunck_pos.x] == 'N'
			|| map[chunck_pos.y][chunck_pos.x] == 'S'
			|| map[chunck_pos.y][chunck_pos.x] == 'E'
			|| map[chunck_pos.y][chunck_pos.x] == 'W')
		{
			player.coordonatef.x = chunck_pos.x * LEN_CHUNCK;
			player.coordonatef.y = chunck_pos.y * LEN_CHUNCK;
			player.rotation
				= init_rotation_player(map[chunck_pos.y][chunck_pos.x]);
			return (player);
		}
		chuck++;
	}
	player.coordonatef.x = 0;
	player.coordonatef.y = 0;
	return (player);
}
