#include "cub3d.h"

int count_wall(t_raycast_info *raycast_info)
{
	int		count;
	int		i;
	int		evolution;
	double	last;

	i = 0;
	count = 1;
	last = raycast_info[0].distance;
	evolution = 0;
	while (raycast_info[i].distance != -1)
	{
		if (last > raycast_info[i].distance && evolution == 1)
			count++;
		else if ((last < raycast_info[i].distance && evolution == -1))
			count++;
		else if (last >= raycast_info[i].distance
				&& last - raycast_info[i].distance > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = raycast_info[i++].distance;
			continue ;
		}
		else if (last < raycast_info[i].distance
				 && raycast_info[i].distance - last > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = raycast_info[i++].distance;
			continue ;
		}
		if (last > raycast_info[i].distance)
			evolution = -1;
		else if (last < raycast_info[i].distance)
			evolution = 1;
		last = raycast_info[i++].distance;
	}
	return (count);
}

double get_end_wall(t_raycast_info *raycast_info, int *i)
{
	int		evolution;
	double	last;

	last = raycast_info[*i].distance;
	evolution = 0;
	while (raycast_info[*i].distance != -1)
	{
		if (last > raycast_info[*i].distance && evolution == 1)
			return (raycast_info[*i - 1].distance);
		else if ((last < raycast_info[*i].distance && evolution == -1))
			return (raycast_info[*i - 1].distance);
		else if (last >= raycast_info[*i].distance
				 && last - raycast_info[*i].distance > LEN_CHUNCK / 2)
			return (raycast_info[*i - 1].distance);
		else if (last < raycast_info[*i].distance
				 && raycast_info[*i].distance - last > LEN_CHUNCK / 2)
			return (raycast_info[*i - 1].distance);
		if (last > raycast_info[*i].distance)
			evolution = -1;
		else if (last < raycast_info[*i].distance)
			evolution = 1;
		last = raycast_info[(*i)++].distance;
	}
	return (raycast_info[*i - 1].distance);
}

t_blocK_wall make_one_block(t_raycast_info *raycast_info, int *i)
{
	int i_start_value;
	t_blocK_wall wall;

	i_start_value = *i;
	wall.start_distance = raycast_info[*i].distance;
	wall.end_distance = get_end_wall(raycast_info, i);
	wall.wall_len = *i - i_start_value;
	return (wall);
}

void init_all_wall(t_blocK_wall *all_wall, t_raycast_info *raycast_info)
{
	int		i;
	int		j;
	double	current_position_pct;

	i = 0;
	j = 0;
	current_position_pct = 0.0;
	while (i < count_wall(raycast_info))
	{
		all_wall[i] = make_one_block(raycast_info, &j);
		all_wall[i].pourcentage_of_screen
			= all_wall[i].wall_len * 100.0 / (FOV / DEGRES_PRECISION + 1);
		all_wall[i].pos_x_start = WITH_SCREEN * current_position_pct / 100;
		current_position_pct += all_wall[i].pourcentage_of_screen;
		all_wall[i].pos_x_end = WITH_SCREEN * current_position_pct / 100;
		all_wall[i].height_start = (int)(HEIGHT_SCREEN * 1.2)
				/ (exp(all_wall[i].start_distance / 300));
		all_wall[i].height_end = (int)(HEIGHT_SCREEN * 1.2)
				/ (exp(all_wall[i].end_distance / 300));
		i++;
	}
	all_wall[i].wall_len = -1.0;
}

t_blocK_wall	*creat_wall_array(t_data data, t_img img, t_raycast_info *raycast_info)
{
	t_blocK_wall	*all_wall;
	(void) data;
	(void) img;

	all_wall = malloc(sizeof(t_blocK_wall) * (count_wall(raycast_info) + 1));
	init_all_wall(all_wall, raycast_info);
	return (all_wall);
}