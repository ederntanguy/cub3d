#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_raycast_info	*ray_info;

	all->is_show_finish = 0;
	show_roof_floor(*(all->img), *(all->textures));
	ray_info = raycasting_minimap(*(all->data));
	show_screen(ray_info, *(all->img), *(all->textures));
	free(ray_info);
	mlx_put_image_to_window(all->window->mlx, all->window->win, all->img->img, 0, 0);
	all->is_show_finish = 1;
	return (0);
}
