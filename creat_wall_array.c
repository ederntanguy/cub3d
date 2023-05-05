#include "cub3d.h"


int count_wall(t_raycast_info *raycast_info)
{
	int				count;
	int				i;
	int				evolution;
	t_raycast_info	last;

	i = 0;
	count = 1;
	last = raycast_info[0];
	evolution = 0;
	while (raycast_info[i].distance != -1)
	{
		if (last.distance > raycast_info[i].distance && evolution == 1)
			count++;
		else if ((last.distance
				  < raycast_info[i].distance
				  && evolution == -1))
			count++;
		else if (last.distance >= raycast_info[i].distance
				 && last.distance - raycast_info[i].distance > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = raycast_info[i++];
			continue ;
		}
		else if (last.distance < raycast_info[i].distance
				 && raycast_info[i].distance - last.distance > LEN_CHUNCK / 2)
		{
			evolution = 0;
			count++;
			last = raycast_info[i++];
			continue ;
		}
		if (last.distance > raycast_info[i].distance)
			evolution = -1;
		else if (last.distance < raycast_info[i].distance)
			evolution = 1;
		last = raycast_info[i++];
	}
	return (count);
}

//int count_wall(t_raycast_info *raycast_info)
//{
//	int				count;
//	int				i;
//	t_coordonate	last_segment;
//
//	i = 0;
//	count = 1;
//	last_segment.x = raycast_info[0].pos.x / 100;
//	last_segment.y = raycast_info[0].pos.y / 100;
//	while (raycast_info[i].distance != -1)
//	{
//		if (raycast_info[i].pos.x / 100 != last_segment.x || raycast_info[i].pos.y / 100 != last_segment.y)
//		{
//			count++;
//			last_segment.x = raycast_info[i].pos.x / 100;
//			last_segment.y = raycast_info[i].pos.y / 100;
//		}
//		i++;
//	}
//	return (count);
//}

double get_end_wall(t_raycast_info *raycast_info, int *i)
{
	int		evolution;
	t_raycast_info	last;

	last = raycast_info[*i];
	evolution = 0;
	while (raycast_info[*i].distance != -1)
	{
		if (last.distance > raycast_info[*i].distance && evolution == 1)
			return (raycast_info[*i - 1].distance);
		else if ((last.distance < raycast_info[*i].distance && evolution == -1))
			return (raycast_info[*i - 1].distance);
		else if (last.distance >= raycast_info[*i].distance
				 && last.distance - raycast_info[*i].distance > LEN_CHUNCK / 2)
			return (raycast_info[*i - 1].distance);
		else if (last.distance < raycast_info[*i].distance
				 && raycast_info[*i].distance - last.distance > LEN_CHUNCK / 2)
			return (raycast_info[*i - 1].distance);
		if (last.distance > raycast_info[*i].distance)
			evolution = -1;
		else if (last.distance < raycast_info[*i].distance)
			evolution = 1;
		last = raycast_info[(*i)++];
	}
	return (raycast_info[*i - 1].distance);
}

//double get_end_wall(t_raycast_info *raycast_info, int *i)
//{
//	t_coordonate	last_segment;
//
//	last_segment.x = raycast_info[*i].pos.x / 100;
//	last_segment.y = raycast_info[*i].pos.y / 100;
//
//	while (raycast_info[*i].distance != -1)
//	{
//		if (raycast_info[*i].pos.x / 100 != last_segment.x || raycast_info[*i].pos.y / 100 != last_segment.y)
//			return (raycast_info[*i].distance);
//		(*i)++;
//	}
//	return (raycast_info[*i - 1].distance);
//}

t_blocK_wall make_one_block(t_raycast_info *raycast_info, int *i)
{
	int i_start_value;
	t_blocK_wall wall;

	i_start_value = *i;
	wall.start_distance = raycast_info[*i].distance;
	wall.end_distance = get_end_wall(raycast_info, i);
	wall.last_inpact = raycast_info[*i - 1].pos;
	wall.first_inpact = raycast_info[i_start_value].pos;
	wall.wall_len = *i - i_start_value;
	return (wall);
}

t_blocK_wall fusion_wall(t_blocK_wall first, t_blocK_wall last)
{
	t_blocK_wall	new;

	new.wall_len = first.wall_len + last.wall_len;
	new.end_distance = last.end_distance;
	new.start_distance = first.start_distance;
	new.pourcentage_of_screen = first.pourcentage_of_screen + last.pourcentage_of_screen;
	new.height_end = last.height_end;
	new.height_start = first.height_start;
	new.pos_x_end = last.pos_x_end;
	new.pos_x_start = first.pos_x_start;
	new.first_inpact = first.first_inpact;
	new.last_inpact = last.last_inpact;
	return (new);
}

void init_all_wall(t_blocK_wall *all_wall, t_raycast_info *raycast_info)
{
	int				i;
	int				j;
	int 			nb_fusion;
	double			current_position_pct;

	i = 0;
	j = 0;
	nb_fusion = 0;
	current_position_pct = 0.0;
	while (i < count_wall(raycast_info) - nb_fusion)
	{
		all_wall[i] = make_one_block(raycast_info, &j);
		all_wall[i].pourcentage_of_screen
				= all_wall[i].wall_len * 100.0 / (FOV / DEGRES_PRECISION + 1);
		all_wall[i].pos_x_start = WITH_SCREEN * current_position_pct / 100;
		current_position_pct += all_wall[i].pourcentage_of_screen;
		all_wall[i].pos_x_end = WITH_SCREEN * current_position_pct / 100;
		all_wall[i].height_start = (int)(HEIGHT_SCREEN * 1.2)
								   / (all_wall[i].start_distance / 100);
		all_wall[i].height_end = (int)(HEIGHT_SCREEN * 1.2)
								 / (all_wall[i].end_distance / 100);
		if (i > 0 && ((all_wall[i].last_inpact.x == all_wall[i].first_inpact.x
					  && (all_wall[i].first_inpact.x == all_wall[i - 1].last_inpact.x)
					  && (all_wall[i - 1].last_inpact.x == all_wall[i - 1].first_inpact.x))
			|| ((all_wall[i].last_inpact.y == all_wall[i].first_inpact.y)
				&& (all_wall[i].first_inpact.y == all_wall[i - 1].last_inpact.y)
				&& (all_wall[i - 1].last_inpact.y == all_wall[i - 1].first_inpact.y))))
		{
			all_wall[i - 1] = fusion_wall(all_wall[i - 1], all_wall[i]);
			nb_fusion++;
			i--;
		}
		i++;
	}
	while (nb_fusion > 0)
		all_wall[i - nb_fusion-- + 1].wall_len = -1;
	all_wall[count_wall(raycast_info)].wall_len = -1;
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