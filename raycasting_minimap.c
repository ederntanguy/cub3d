#include "cub3d.h"

void draw_line(t_data data, t_coordonatef pos, t_img img)
{
	float i;

	(void) data;
	i = 0.0;
	while (i < LEN_RAYCAST)
	{
		my_mlx_pixel_put(&img, (int)ceil(i / (float)(LEN_CHUNCK / LEN_CHUNCK_MAP) * pos.x), (int)ceil(i / (float)(LEN_CHUNCK / LEN_CHUNCK_MAP) * pos.y), 0x00FFFF00);
		i++;
	}
}

void calcul_draw_line(float degres, t_data data, t_img	img)
{
	double			radians;
	t_coordonatef	pos;
	float 			i;

	i = 0.0;
	radians = PI * degres / 180;
//	printf("rad = %lf degres = ")

	while (i < LEN_RAYCAST)
	{
		pos.x = i / (LEN_CHUNCK / LEN_CHUNCK_MAP) * cos(radians) + data.player.coordonate.x / (LEN_CHUNCK / LEN_CHUNCK_MAP);
		pos.y = i / (LEN_CHUNCK / LEN_CHUNCK_MAP) * sin(radians) + data.player.coordonate.y / (LEN_CHUNCK / LEN_CHUNCK_MAP);
		my_mlx_pixel_put(&img, (int)ceil(pos.x), (int)ceil(pos.y), 0x00FFFF00);
		i+=20;
	}
}

void raycasting_minimap(t_data data, t_img img)
{
	float degres;

	degres = (float)(data.player.rotation) - FOV / 2.0;

	while (degres < (float)(data.player.rotation) + FOV / 2.0)
	{
		calcul_draw_line(degres, data, img);
		degres++;
	}
}