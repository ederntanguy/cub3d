#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_img			img;
	t_raycast_info	*ray_info;

	img.img = mlx_new_image(all->window->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
//	show_map(img, all->data->map);
//	show_player_mini_map(img, all->data->player);
	show_roof_floor(img, *(all->data));
	ray_info = raycasting_minimap(*(all->data));
	show_screen(ray_info, img);
	mlx_put_image_to_window(all->window->mlx, all->window->win, img.img, 0, 0);
	return (0);
}
