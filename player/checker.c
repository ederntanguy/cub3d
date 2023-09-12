/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:28:29 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:35:47 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_corners(int x, int y, t_data data)
{
	if (data.map[y / LEN_CHUNCK][x / LEN_CHUNCK] == '1'
		|| data.map[(y + PLAYER_SIZE + COLLISION_EXTRA_BORDER)
		/ LEN_CHUNCK][x / LEN_CHUNCK] == '1'
		|| data.map[(y + PLAYER_SIZE + COLLISION_EXTRA_BORDER)
		/ LEN_CHUNCK][(x + PLAYER_SIZE + COLLISION_EXTRA_BORDER)
		/ LEN_CHUNCK] == '1'
		|| data.map[y / LEN_CHUNCK][(x + PLAYER_SIZE
		+ COLLISION_EXTRA_BORDER) / LEN_CHUNCK] == '1')
		return (0);
	return (1);
}

t_coordonatef	check_posible_position(t_coordonatef possible, t_data data)
{
	if (check_corners(round_float(possible.x), round_float(possible.y), data))
		return (possible);
	else if (check_corners(round_float(possible.x),
			round_float(data.player.coordonatef.y), data))
	{
		data.player.coordonatef.x = possible.x;
		return (data.player.coordonatef);
	}
	else if (check_corners(round_float(data.player.coordonatef.x),
			round_float(possible.y), data))
	{
		data.player.coordonatef.y = possible.y;
		return (data.player.coordonatef);
	}
	return (data.player.coordonatef);
}
