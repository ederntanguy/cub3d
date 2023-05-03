#include "cub3d.h"

void show_management_line(t_img img, int pos_x, int height, int color)
{
	int hgt_scrn;
	int y;

	hgt_scrn = HEIGHT_SCREEN;
	y = (hgt_scrn - height) / 2;
	while (y < hgt_scrn - (hgt_scrn - height) / 2)
	{
		my_mlx_pixel_put(&img, pos_x, y, color);
		y++;
	}
}

void show_screen(t_blocK_wall *all_wall, t_img img)
{
	int i;
	int color;

	color = 0x0000FF;

	i = 0;
	while (all_wall[i].wall_len != -1.0)
	{
		show_management_line(img, all_wall[i].pos_x_start, all_wall[i].height_start, color);
		show_management_line(img, all_wall[i].pos_x_end - 1, all_wall[i].height_end, color);
		color *= 16;
		i++;
	}
}