#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_raycast_info	*ray_info;

	show_roof_floor(*(all->img), *(all->textures));
	ray_info = raycasting_minimap(*(all->data));
	show_screen(ray_info, *(all->img), *(all->textures));
	free(ray_info);
	show_map(*(all->img), all->data->map);
//	show_player_mini_map(img, all->data->player);
	mlx_put_image_to_window(all->window->mlx, all->window->win, all->img->img, 0, 0);
	return (0);
}
