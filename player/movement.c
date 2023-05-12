#include "../cub3d.h"
#include <math.h>
#include <stdio.h>

void	move(t_data	*data, double x, double y)
{
	t_coordonatef	initial_vector;
	t_coordonatef	new_position;
	printf("%d\n",data.map[possible.y / LEN_CHUNCK][possible.x / LEN_CHUNCK]);
	if (possible.x / LEN_CHUNCK < PlAYER_SIZE
		&& possible.y / LEN_CHUNCK < PlAYER_SIZE
		&& data.map[possible.y / LEN_CHUNCK][possible.x / LEN_CHUNCK] == 0)
		return (write(1, "OK\n", 3));
	return (0);
}

	initial_vector.x = x;
	initial_vector.y = y;
	initial_vector = rotate_vector(initial_vector,
			data->player.rotation);
	new_position = add_vector(initial_vector, data->player.coordonate);
	data->player.coordonate = check_posible_position(new_position, *data);
}

void	rotate_player(t_all *all, int rotation)
{
	all->data.player.rotation += rotation;
			data->player.coordonatef, data->player.rotation);
	new_position = add_vector(initial_vector, data->player.coordonatef);
	if (check_posible_position(new_position, *data))
		data->player.coordonatef = new_position;
}
