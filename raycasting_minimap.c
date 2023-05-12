#include "cub3d.h"

int is_in_wall_chunck(t_data data, t_coordonatef pos)
{
	if (data.map[(int)(pos.y / 100)][(int)(pos.x / 100)] == '1')
		return (0);
	return (1);
}

void calcul_draw_line(float degres, t_data data, t_img	img)
{
	double			radians;
	t_coordonatef	pos;
	float 			i;

	i = 0.0;
	radians = PI * degres / 180;

	while (i < LEN_RAYCAST)
	{
		pos.x = i * cos(radians) + data.player.coordonate.x + LEN_CHUNCK / 2;
		pos.y = i * sin(radians) + data.player.coordonate.y + LEN_CHUNCK / 2;
		if (is_in_wall_chunck(data, pos) == 0)
			break ;
		my_mlx_pixel_put(&img, (int)ceil(pos.x / (LEN_CHUNCK / LEN_CHUNCK_MAP)), (int)ceil(pos.y / (LEN_CHUNCK / LEN_CHUNCK_MAP)), 0x00FFFF00);
		i+=1;
	}
}

void raycasting_minimap(t_data data, t_img img)
{
	float degres;

	degres = (float)(data.player.rotation) - FOV / 2.0;
 
	while (degres < (float)(data.player.rotation) + FOV / 2.0)
	{
		calcul_draw_line(degres, data, img);
		degres+=0.05;
	}
}