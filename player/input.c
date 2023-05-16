#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
	if (keycode == 65307)
		quit(all);
	if (all->is_show_finish)
	{
		if (keycode == 'd')
			move((all->data), 0.0, -50.0);
		else if (keycode == 'a')
			move((all->data), 0.0, 50.0);
		else if (keycode == 's')
			move((all->data), -50.0, 0);
		else if (keycode == 'w')
			move((all->data), 50.0, 0);
		else if (keycode == 65361)
			rotate_player(all, -5);
		else if (keycode == 65363)
			rotate_player(all, 5);
		if (keycode == 'w' || keycode == 's' || keycode == 'a' || keycode == 'd' || keycode == 65361 || keycode == 65363)
			show_debug_map(all);
	}
	return (1);
}
