/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:01:15 by gde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 13:00:22 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	make_player(char **map)
{
	t_player		player;
	t_coordonate	chunck_pos;
	int				chunck;

	chunck = 0;
	chunck_pos.y = 0;
	while (map[chunck_pos.y])
	{
		calcule_coordonate_chunck(chunck, &(chunck_pos.x), &(chunck_pos.y), map);
		if (map[chunck_pos.y][chunck_pos.x] == 'N'
			|| map[chunck_pos.y][chunck_pos.x] == 'S'
			|| map[chunck_pos.y][chunck_pos.x] == 'E'
			|| map[chunck_pos.y][chunck_pos.x] == 'W')
		{
			player.coordonate.x = chunck_pos.x * LEN_CHUNCK;
			player.coordonate.y = chunck_pos.y * LEN_CHUNCK;
			if (map[chunck_pos.y][chunck_pos.x] == 'N')
				player.rotation = 270;
			else if (map[chunck_pos.y][chunck_pos.x] == 'E')
				player.rotation = 0;
			else if (map[chunck_pos.y][chunck_pos.x] == 'S')
				player.rotation = 90;
			else if (map[chunck_pos.y][chunck_pos.x] == 'W')
				player.rotation = 180;
			return (player);
		}
		chunck++;
	}
	player.coordonate.x = 0;
	return (player);
}
