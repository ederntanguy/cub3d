#include "../cub3d.h"

int	input_handling(int keycode, t_all *all)
{

	if (keycode == 'd')
	{
<<<<<<< HEAD
		move(&(all->data), 0.0, -10.0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 'q')
	{
		move(&(all->data), 0.0, 10.0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 's')
	{
		move(&(all->data), -10.0, 0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 'z')
	{
		move(&(all->data), 10.0, 0);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 65361)
	{
		rotate_player(all, -1);
		show_debug_map(&(all->data), &(all->window));
	}
	else if (keycode == 65363)
	{
		rotate_player(all, 1);
=======
<<<<<<< HEAD
//		move_up(data);
		all->data->player.coordonatef.y -= 100;
		show_debug_map(all);
//		printf("ici\n");
=======
		move_up(&(all->data));
>>>>>>> relou
		show_debug_map(&(all->data), &(all->window));
>>>>>>> main
	}
	return (1);
}
