#include "../cub3d.h"

int	check_x(t_coordonatef possible, t_data data)
{
	int	x;
	int	y;

	x = roundFloat(possible.x);
	y = roundFloat(possible.y);
	if (x % LEN_CHUNCK < PlAYER_SIZE && x % LEN_CHUNCK != 0 && data.map[y / LEN_CHUNCK][x / LEN_CHUNCK - 1])
	{
		printf("COLLISION MUR GAUCHE\n");
		return (0);
	}
	else if (x % LEN_CHUNCK > LEN_CHUNCK - PlAYER_SIZE && data.map[y / LEN_CHUNCK][x / LEN_CHUNCK + 1])
	{
		printf("COLLISION MUR DROITE\n");
		return (0);
	}
	return (1);
}

int check_y(t_coordonatef possible, t_data data)
{
	int	x;
	int	y;

	x = (int)(possible.x < 0 ? (possible.x - 0.5) : (possible.x + 0.5));
	y = (int)(possible.y < 0 ? (possible.y - 0.5) : (possible.y + 0.5));
	if (y % LEN_CHUNCK < PlAYER_SIZE && data.map[y / LEN_CHUNCK][x / LEN_CHUNCK])
	{
		printf("COLLISION MUR HAUT en %d | %d\n", y / LEN_CHUNCK, x / LEN_CHUNCK);
		return (0);
	}
	else if (y % LEN_CHUNCK > LEN_CHUNCK - PlAYER_SIZE && data.map[y / LEN_CHUNCK + 1][x / LEN_CHUNCK])
	{
		printf("COLLISION MUR BAS\n");
		return (0);
	}
	return (1);
}

int	check_posible_position(t_coordonatef possible, t_data data)
{
	if (check_x(possible, data) && check_y(possible, data))
		return (1);
	return (0);
}
