#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{
	if (keycode == 65362)
	{
		move(&(all->data), 0.0, -10.0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 65364)
	{
		move(&(all->data), 0.0, 10.0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 65361)
	{
		move(&(all->data), -10.0, 0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 65363)
	{
		move(&(all->data), 10.0, 0);
		show_debug_map(&(all->data), &(all->window));
	}
	return (1);
}
