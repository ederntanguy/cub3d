#include "../cub3d.h"

void	show_roof(t_img img, int color)
{
	int	x;
	int y;

	x = 0;
	while (x < WITH_SCREEN)
	{
		y = 0;
		while (y < HEIGHT_SCREEN / 2)
		{
			my_mlx_pixel_put(&img, x, y++, color);
		}
		x++;
	}
}

void	show_floor(t_img img, int color)
{
	int	x;
	int y;

	x = 0;
	while (x < WITH_SCREEN)
	{
		y = HEIGHT_SCREEN / 2;
		while (y < HEIGHT_SCREEN)
		{
			my_mlx_pixel_put(&img, x, y++, color);
		}
		x++;
	}
}

void show_roof_floor(t_img img, t_data data)
{
	data.floor_color = 0xFF0000;
	data.roof_color = 0xFFFF00;
	show_floor(img, data.floor_color);
	show_roof(img, data.roof_color);
}