#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
//	if (keycode == 65362)
//	{
//		move_up(data);
		all->data->player.coordonatef.y -= 10;
		show_debug_map(all);
		printf("ici %d\n", keycode);
//	}
	return (1);
}
