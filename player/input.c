#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
	if (keycode == 65362)
	{
		move_up(&(all->data));
		show_debug_map(&(all->data), &(all->window));
	}
	return (1);
}
