#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_img			img;
	double			*raycast_info;

	img.img = mlx_new_image(all->window->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	show_map(img, all->data->map);
	show_player_mini_map(img, all->data->player);
	raycast_info = raycasting_minimap(*(all->data), img);
	show_screen(raycast_info, img);
	mlx_put_image_to_window(all->window->mlx, all->window->win, img.img, 0, 0);
	return (0);
}
