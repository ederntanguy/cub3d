#include "cub3d.h"

int count_wall(double *distance_pts_array)
{
	int		count;
	int		i;
	int		evolution;
	double	last;

	i = 0;
	count = 1;
	last = distance_pts_array[0];
	evolution = 0;
	while (distance_pts_array[i] != -1)
	{
		if (last > distance_pts_array[i] && evolution == 1)
			count++;
		else if ((last < distance_pts_array[i] && evolution == -1))
			count++;
		else if (last >= distance_pts_array[i]
				&& last - distance_pts_array[i] > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = distance_pts_array[i++];
			continue ;
		}
		else if (last < distance_pts_array[i]
				 && distance_pts_array[i] - last > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = distance_pts_array[i++];
			continue ;
		}
		if (last > distance_pts_array[i])
			evolution = -1;
		else if (last < distance_pts_array[i])
			evolution = 1;
		last = distance_pts_array[i++];
	}
	return (count);
}

double get_end_wall(double *distance_pts_array, int *i)
{
	int		evolution;
	double	last;

	last = distance_pts_array[*i];
	evolution = 0;
	while (distance_pts_array[*i] != -1)
	{
		if (last > distance_pts_array[*i] && evolution == 1)
			return (distance_pts_array[*i - 1]);
		else if ((last < distance_pts_array[*i] && evolution == -1))
			return (distance_pts_array[*i - 1]);
		else if (last >= distance_pts_array[*i]
				 && last - distance_pts_array[*i] > LEN_CHUNCK / 2)
			return (distance_pts_array[*i - 1]);
		else if (last < distance_pts_array[*i]
				 && distance_pts_array[*i] - last > LEN_CHUNCK / 2)
			return (distance_pts_array[*i - 1]);
		if (last > distance_pts_array[*i])
			evolution = -1;
		else if (last < distance_pts_array[*i])
			evolution = 1;
		last = distance_pts_array[(*i)++];
	}
	return (distance_pts_array[*i - 1]);
}

t_blocK_wall make_one_block(double *distance_pts_array, int *i)
{
	int i_start_value;
	t_blocK_wall wall;

	i_start_value = *i;
	wall.start_distance = distance_pts_array[*i];
	wall.end_distance = get_end_wall(distance_pts_array, i);
	wall.wall_len = *i - i_start_value;
	return (wall);
}

void init_all_wall(t_blocK_wall *all_wall, double *distance_pts_array)
{
	int		i;
	int		j;
	double	current_position_pct;

	i = 0;
	j = 0;
	current_position_pct = 0.0;
	while (i < count_wall(distance_pts_array))
	{
		all_wall[i] = make_one_block(distance_pts_array, &j);
		all_wall[i].pourcentage_of_screen
			= all_wall[i].wall_len * 100.0 / (FOV / DEGRES_PRECISION + 1);
		all_wall[i].pos_x_start = WITH_SCREEN * current_position_pct / 100;
		current_position_pct += all_wall[i].pourcentage_of_screen;
		all_wall[i].pos_x_end = WITH_SCREEN * current_position_pct / 100;
		all_wall[i].height_start = (int)(HEIGHT_SCREEN * 1.2)
				/ (exp(all_wall[i].start_distance / 500));
		all_wall[i].height_end = (int)(HEIGHT_SCREEN * 1.2)
				/ (exp(all_wall[i].end_distance / 500));
		i++;
	}
	all_wall[i].wall_len = -1.0;
}

t_blocK_wall	*creat_wall_array(t_data data, t_img img, double *distance_pts_array)
{
	t_blocK_wall	*all_wall;
	(void) data;
	(void) img;
	(void) distance_pts_array;
	all_wall = malloc(sizeof(t_blocK_wall) * (count_wall(distance_pts_array) + 1));
	init_all_wall(all_wall, distance_pts_array);
	return (all_wall);
}