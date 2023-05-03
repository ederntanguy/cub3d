#include "cub3d.h"

int is_in_wall_chunck(t_data data, t_coordonatef pos)
{
	if (data.map[(int)(pos.y / 100)][(int)(pos.x / 100)] == '1')
		return (0);
	return (1);
}

t_raycast_info all_info_raycast_collision(t_data data, double radians, int i)
{
	t_raycast_info	res;

	res.pos.x = (int)(i * cos(radians) + data.player.coordonate.x);
	res.pos.y = (int)(i * sin(radians) + data.player.coordonate.y);
	res.distance = sqrt((res.pos.x - data.player.coordonate.x)
			* (res.pos.x - data.player.coordonate.x)
			+ (res.pos.y - data.player.coordonate.y)
			* (res.pos.y - data.player.coordonate.y));
	return (res);
}

t_raycast_info calcul_draw_line(double degres, t_data data, t_img	img)
{
	double			radians;
	t_coordonatef	pos;
	double 			i;
	t_raycast_info	collision_info;

	i = 0.0;
	radians = PI * degres / 180;
	while (i < LEN_RAYCAST)
	{
		pos.x = i * cos(radians) + data.player.coordonate.x;
		pos.y = i * sin(radians) + data.player.coordonate.y;
		if (is_in_wall_chunck(data, pos) == 0)
		{
			collision_info = all_info_raycast_collision(data, radians, i);
			return (collision_info);
		}
		my_mlx_pixel_put(&img, (int)ceil(pos.x / (LEN_CHUNCK / LEN_CHUNCK_MAP)), (int)ceil(pos.y / (LEN_CHUNCK / LEN_CHUNCK_MAP)), 0x00FFFF00);
		i += 1;
	}
	collision_info.distance = 1.0;
	return (collision_info);
}

t_raycast_info *raycasting_minimap(t_data data, t_img img)
{
	double			degres;
	t_raycast_info	*raycast_info;
	int 	i;

	i = 0;
	raycast_info = malloc(sizeof(t_raycast_info) * (int)((double)FOV / DEGRES_PRECISION + 2));
	degres = (float)(data.player.rotation) - FOV / 2.0;
	raycast_info[(int)((double)FOV / DEGRES_PRECISION + 1)].distance = -1;
	while (degres < (float)(data.player.rotation) + FOV / 2.0)
	{
		raycast_info[i++] = calcul_draw_line(degres, data, img);
		degres += DEGRES_PRECISION;
	}
	return (raycast_info);
}