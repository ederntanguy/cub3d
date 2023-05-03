#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
	if (keycode == 65362)
	{
//		move_up(data);
		all->data->player.coordonate.y -= 100;
		show_debug_map(all);
//		printf("ici\n");
	}
	return (1);
}
