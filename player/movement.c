#include "../cub3d.h"
#include <math.h>
#include <stdio.h>

int	which_to_check(double x)
{
	if (round(x) / LEN_CHUNCK > LEN_CHUNCK - PlAYER_SIZE)
		return (round(x) / LEN_CHUNCK - PlAYER_SIZE);
	else if () {
	
	}
}s

int	check_posible_position(t_coordonatef possible, t_data data)
{
	if (possible.x / LEN_CHUNCK < PlAYER_SIZE
		&& possible.y / LEN_CHUNCK < PlAYER_SIZE
		&& data.map[which_to_check(possible.y)]
		[which_to_check(possible.x)] != 0)
		return (1);
	return (0);
}

void	move_up(t_data	*data)
{
	t_coordonatef	initial_vector;
	t_coordonatef	new_position;

	initial_vector.x = 0.0;
	initial_vector.y = -PLAYER_SPEED;
	initial_vector = rotate_vector(initial_vector,
			data->player.rotation);
	new_position = add_vector(initial_vector, data->player.coordonate);
	if (check_posible_position(new_position, *data))
		data->player.coordonate = new_position;
}
