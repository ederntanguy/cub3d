#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_img			img;
	t_raycast_info	*ray_info;

	img.img = mlx_new_image(all->window->mlx, 1920, 1080);
	img.addr = (unsigned char *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
												  &img.endian);
	show_roof_floor(img, all->textures);
	ray_info = raycasting_minimap(*(all->data));
	show_screen(ray_info, img, all->textures);
	free(ray_info);
	show_map(img, all->data->map);
//	show_player_mini_map(img, all->data->player);
	mlx_put_image_to_window(all->window->mlx, all->window->win, img.img, 0, 0);
	return (0);
}
