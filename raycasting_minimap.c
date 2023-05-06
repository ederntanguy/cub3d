#include "cub3d.h"

int is_in_wall_chunck(char **map, t_coordonate pos)
{
		if (map[pos.y / 100][pos.x / 100] == '1')
			return (0);
	return (1);
}

t_raycast_info all_info_raycast_collision(t_data data, double radians, double i)
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

char side_collision(t_data data, t_raycast_info collision_info)
{
	static char last;

	if ((int)collision_info.pos.y % 100 == 0 && (int)collision_info.pos.x % 100 == 0)
		return (last);
	if ((int)collision_info.pos.y % 100 == 0)
	{
		if (data.map[(int)collision_info.pos.y / 100][(int)collision_info.pos.x / 100] == '1')
		{
			last = 'T';
			return ('T');
		}
		else
		{
			last = 'B';
			return ('B');
		}
	}
	else
	{
		if (data.map[(int)collision_info.pos.y / 100][(int)collision_info.pos.x / 100] == '1')
		{
			last = 'L';
			return ('L');
		}
		else
		{
			last = 'R';
			return ('R');
		}
	}
}

void sort_doubl_tab(double *tab, int len)
{
	int		i;
	int 	j;
	double	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (j + 1 < len && tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

double	creat_i_value(double radians, t_coordonate player_pos, char **map)
{
	int				i;
	double 			value;
	t_coordonate	pos;

	i = ceil(player_pos.x / 100);
	while (i < ft_strlen(map[0]))
	{
		value = ((double)i * 100.0 - player_pos.x) / cos(radians);
		pos.x = (int)(value * cos(radians) + player_pos.x);
		pos.y = (int)(value * sin(radians) + player_pos.y);
		if (is_in_wall_chunck(map, pos) == 0)
			return (value);
		i++;
	}
	i = ceil(player_pos.y / 100);
	while (i < ft_dbstrlen(map))
	{
		value = ((double)i * 100.0 - player_pos.y) / cos(radians);
		pos.x = (int)(value * cos(radians) + player_pos.x);
		pos.y = (int)(value * sin(radians) + player_pos.y);
		if (is_in_wall_chunck(map, pos) == 0)
			return (value);
	}
	return (1.0);
}

t_raycast_info calcul_draw_line(double degres, t_data data)
{
	double			radians;
	double			i;
	t_raycast_info	collision_info;

	radians = PI * degres / 180;
	i = creat_i_value(radians, data.player.coordonate, data.map);
	collision_info = all_info_raycast_collision(data, radians, i);
	collision_info.side = side_collision(data, collision_info);
	return (collision_info);
//	my_mlx_pixel_put(&img, (int)ceil(pos.x / (LEN_CHUNCK / LEN_CHUNCK_MAP)), (int)ceil(pos.y / (LEN_CHUNCK / LEN_CHUNCK_MAP)), 0x00FFFF00);
}

t_raycast_info *raycasting_minimap(t_data data)
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
		raycast_info[i++] = calcul_draw_line(degres, data);
		degres += DEGRES_PRECISION;
	}
	return (raycast_info);
}