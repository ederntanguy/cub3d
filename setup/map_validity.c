/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:32:31 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 14:52:46 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	invalid_character(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == ' '
					|| map[y][x] == '1' || map[y][x] == '\n'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_hole(char **map, int x, int y)
{
	if (x == 0 || y == 0
		|| (y != 0 && ((x != 0 && empty(map[y - 1][x - 1]))
			|| empty(map[y - 1][x]) || (map[y - 1][x + 1]
		&& empty(map[y - 1][x + 1]))))
		|| ((x != 0 && empty(map[y][x - 1]))
		&& (map[y][x + 1] && empty(map[y][x + 1])))
		|| (map[y + 1] != NULL && ((x != 0 && empty(map[y + 1][x - 1]))
		|| empty(map[y + 1][x]) || (map[y + 1][x + 1]
		&& empty(map[y + 1][x + 1])))))
		return (1);
	return (0);
}

int	hole_in_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
					&& is_hole(map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	missing_player(char **map)
{
	int	player;
	int	x;
	int	y;

	y = 0;
	player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'S' || map[y][x] == 'N'
					|| map[y][x] == 'W' || map[y][x] == 'E')
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	map_validity(char **map)
{
	if (!map)
		return (ft_putstr_fd("Error\nMalloc of map failed\n", 2), 0);
	if (invalid_character(map))
		return (ft_putstr_fd("Error\nThe Map countain Invalid characters\n",
				2), 0);
	if (missing_player(map))
		return (ft_putstr_fd("Error\nInvalid number of player\n", 2), 0);
	if (hole_in_map(map))
		return (ft_putstr_fd("Error\nWall aren't closed\n", 2), 0);
	return (1);
}
