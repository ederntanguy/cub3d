/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:01:15 by gde-carv          #+#    #+#             */
/*   Updated: 2023/05/02 11:11:38 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	make_player(int x, int y, char direction)
{
	t_player	player;
	
	player.coordonate.x = x;
	player.coordonate.y = y;
	if (direction == 'n')
		player.rotation = 0;
	if (direction == 'e')
		player.rotation = 90;
	if (direction == 's')
		player.rotation = 180;
	if (direction == 'w')
		player.rotation = 270;
}