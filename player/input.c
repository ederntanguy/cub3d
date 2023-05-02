#include "../cub3d.h"

int	input_handling(int keycode, t_data *data)
{
	if (keycode == 65362)
	{
//		move_up(data);
		data->player.coordonate.x += 100;
		printf("ici\n");
	}
	return (1);
}
