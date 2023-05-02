#include "../cub3d.h"

int	check_posible_position(t_coordonate possible, t_data data)
{
	if (possible.x / LEN_CHUNCK < PlAYER_SIZE
		&& possible.y / LEN_CHUNCK < PlAYER_SIZE
		&& data.map[possible.y / LEN_CHUNCK][possible.x / LEN_CHUNCK] != 0)
		return (1);
	return (0);
}

void	move_up(t_data	*data)
{
	t_coordonate	initial_vector;
	t_coordonate	new_position;

	initial_vector.x = PLAYER_SPEED;
	initial_vector.y = 0;
	initial_vector = rotate_vector(initial_vector,
			data->player.coordonate, data->player.rotation);
	new_position = add_vector(initial_vector, data->player.coordonate);
	if (check_posible_position(new_position, *data))
		data->player.coordonate = new_position;
}
