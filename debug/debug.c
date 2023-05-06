#include "../cub3d.h"

int	show_debug_map(t_all *all)
{
	t_img			img;
	t_blocK_wall	*all_wall;
	t_raycast_info	*raycast_info;

	img.img = mlx_new_image(all->window->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	show_map(img, all->data->map);
	show_player_mini_map(img, all->data->player);
	raycast_info = raycasting_minimap(*(all->data));
	all_wall = creat_wall_array(*(all->data), img, raycast_info);
	show_screen(all_wall, img);
	mlx_put_image_to_window(all->window->mlx, all->window->win, img.img, 0, 0);
	return (0);
}
