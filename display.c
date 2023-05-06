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
	hgt_scrn = HEIGHT_SCREEN;
	len_line = sqrt(pow((hgt_scrn - all_wall.height_start) / 2
						- (hgt_scrn - all_wall.height_end) / 2, 2)
					+ pow(all_wall.pos_x_start - all_wall.pos_x_end, 2));
	radian = acos((all_wall.pos_x_end - all_wall.pos_x_start) / len_line);
	if (all_wall.start_distance > all_wall.end_distance)
		radian = -radian;
	while (i < len_line)
	{
		pos.x = i * cos(radian) + all_wall.pos_x_start;
		pos.y = i * sin(radian) + (hgt_scrn - all_wall.height_start) / 2;
		my_mlx_pixel_put(&img, pos.x, pos.y, color);
		pos.y = i++ * sin(-radian) + (hgt_scrn - (hgt_scrn - all_wall.height_start) / 2);
		my_mlx_pixel_put(&img, pos.x, pos.y, color);
	}
}

void	show_screen(t_blocK_wall *all_wall, t_img img)
{
	int i;
	int color;
	int color2;

	color = 0x0000FF;
	color2 = 0x00FF00;

	i = 0;
	while (all_wall[i].wall_len != -1.0)
	{
		show_right_left_line(img, all_wall[i].pos_x_start, all_wall[i].height_start, color);
		show_right_left_line(img, all_wall[i].pos_x_end - 1, all_wall[i].height_end, color);
		if (i == 2)
			show_bottom_top_line(img, all_wall[i], color2);
		else
			show_bottom_top_line(img, all_wall[i], color);
		i++;
	}
}