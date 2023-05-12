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

void show_roof_floor(t_img img, t_textures textures)
{
	show_floor(img, textures.floor);
	show_roof(img, textures.roof);
}