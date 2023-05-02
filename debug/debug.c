#include "../cub3d.h"

void	show_debug_map(t_data *data, t_window *window)
{
	t_img		img;

	img.img = mlx_new_image(window->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	show_map(img, data->map);
	show_player_mini_map(img, data->player);
	mlx_put_image_to_window(window->mlx, window->win, img.img, 0, 0);
}
