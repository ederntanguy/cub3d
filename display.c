#include "cub3d.h"

void	show_right_left_line(t_img img, int pos_x, int height, int color)
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

void	show_bottom_top_line(t_img img, t_blocK_wall all_wall, int color)
{
	double			len_line;
	int				hgt_scrn;
	double			radian;
	int				i;
	t_coordonate	pos;

	i = 0;
	(void) img;
	(void) color;
	hgt_scrn = HEIGHT_SCREEN;
	len_line = sqrt(pow((hgt_scrn - all_wall.height_start) / 2
				- (hgt_scrn - all_wall.height_end) / 2, 2)
				+ pow(all_wall.pos_x_start - all_wall.pos_x_end, 2));
	radian = acos((all_wall.pos_x_end - all_wall.pos_x_start) / len_line);
	while (i < len_line)
	{
		pos.x = i * cos(radian) + all_wall.pos_x_start;
		pos.y = i * sin(radian) + (hgt_scrn - all_wall.height_start) / 2;
		my_mlx_pixel_put(&img, pos.x, pos.y, color);
		pos.x = i * cos(- radian) + all_wall.pos_x_start;
		pos.y = i * sin(- radian) + (hgt_scrn - (hgt_scrn - all_wall.height_start) / 2);
		my_mlx_pixel_put(&img, pos.x, pos.y, color);
		i++;
	}
	printf("length = %lf rad = %lf\n", len_line, radian);
}

void	show_screen(t_blocK_wall *all_wall, t_img img)
{
	int i;
	int color;

	color = 0x0000FF;

	i = 0;
	while (all_wall[i].wall_len != -1.0)
	{
		show_right_left_line(img, all_wall[i].pos_x_start, all_wall[i].height_start, color);
		show_right_left_line(img, all_wall[i].pos_x_end - 1, all_wall[i].height_end, color);
		color *= 16;
		show_bottom_top_line(img, all_wall[i], color);
		i++;
	}
}