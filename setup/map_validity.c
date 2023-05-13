#include "../cub3d.h"

int empty(char c)
{
	if (c == ' ' || c == '0')
		return (1);
	return (0);
}

int	is_hole(char **map, int x, int y)
{
	if (map[y - 1][x - 1] == ' ' || )
}

int hole_in_map(char **map)
{
    int i;

	i = 0;
    while (map[0][i])
	{
        if (map[0][i] == '0' || map[ft_tablen(map) - 1][i] == '0')
            return (1);
        i++;
    }
	i = 0;
    while (map[i])
	{
        if (map[i][0] == '0' || map[i][ft_strlen(map[i]) - 1] == '0')
            return (1);
        i++;
    }
	return (0);
}

int	missing_player(char **map)
{
	int	player;
	int	x;
	int y;

	y = 0;
	player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'S' || map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E')
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
		return (ft_putstr_fd("Malloc of map failed\n", 2), 0);
	if (missing_player(map))
		return (ft_putstr_fd("Invalid number of player\n", 2), 0);
	if (hole_in_map(map))
		return (ft_putstr_fd("Wall aren't closed\n", 2), 0);
	return (1);
}
