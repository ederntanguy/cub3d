#include "../cub3d.h"

int	check_corners(int x, int y, t_data data)
{
	if (data.map[y / LEN_CHUNCK][x / LEN_CHUNCK] == '1'
		|| data.map[(y + PlAYER_SIZE) / LEN_CHUNCK][x / LEN_CHUNCK] == '1'
		|| data.map[(y + PlAYER_SIZE) / LEN_CHUNCK][(x + PlAYER_SIZE) / LEN_CHUNCK] == '1'
		|| data.map[y / LEN_CHUNCK][(x + PlAYER_SIZE) / LEN_CHUNCK] == '1')
		return (0);
	return (1);
}

t_coordonatef check_posible_position(t_coordonatef possible, t_data data)
{
	if (check_corners(roundFloat(possible.x), roundFloat(possible.y), data))
		return (possible);
	else if (check_corners(roundFloat(possible.x), roundFloat(data.player.coordonatef.y), data))
	{
		data.player.coordonatef.x = possible.x;
		return (data.player.coordonatef);
	}
	else if (check_corners(roundFloat(data.player.coordonatef.x), roundFloat(possible.y), data))
	{
		data.player.coordonatef.y = possible.y;
		return (data.player.coordonatef);
	}
	return (data.player.coordonatef);
}
