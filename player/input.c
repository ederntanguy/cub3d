#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
	if (keycode == 'd')
	{
		move((all->data), 0.0, -10.0);
		show_debug_map(all);
	}
	else if (keycode == 'a')
	{
		move((all->data), 0.0, 10.0);
        show_debug_map(all);
	}
	else if (keycode == 's')
	{
		move((all->data), -10.0, 0);
        show_debug_map(all);
	}
	else if (keycode == 'w')
	{
		move((all->data), 10.0, 0);
        show_debug_map(all);
	}
	else if (keycode == 65361)
	{
		rotate_player(all, -1);
		show_debug_map(all);
	}
	else if (keycode == 65363)
	{
		rotate_player(all, 1);
		show_debug_map(all);
	}
	return (1);
}
