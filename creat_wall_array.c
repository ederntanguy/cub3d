#include "cub3d.h"

int count_wall(t_raycast_info *raycast_info)
{
	int				nb_wall;
	int 			i;
	t_coordonate	last;

	i = 0;
	nb_wall = 0;
	last.x = -1;
	last.y = -1;
	while (raycast_info[i].distance != -1)
	{
		if ((raycast_info[i].side == 'T' || raycast_info[i].side == 'B') && raycast_info[i].pos.x / 100 != last.x)
		{
			last.x = raycast_info[i].pos.x / 100;
			last.y = raycast_info[i].pos.y / 100;
			nb_wall++;
		}
		else if ((raycast_info[i].side == 'R' || raycast_info[i].side == 'L') && raycast_info[i].pos.y / 100 != last.y)
		{
			last.x = raycast_info[i].pos.x / 100;
			last.y = raycast_info[i].pos.y / 100;
			nb_wall++;
		}
		i++;
	}
	return (nb_wall);
}

double get_end_wall(t_raycast_info *raycast_info, int *i)
{
	t_coordonate	last;
	char			last_side;

	last_side = raycast_info[*i].side;
	last.x = raycast_info[*i].pos.x / 100;
	last.y = raycast_info[*i].pos.y / 100;

	while (raycast_info[*i].distance != -1)
	{
		if (last_side !=  raycast_info[*i].side)
			return (raycast_info[(*i) - 1].distance);
		if ((raycast_info[*i].side == 'T' || raycast_info[*i].side == 'B') && raycast_info[*i].pos.x / 100 != last.x)
			return (raycast_info[(*i) - 1].distance);
		else if ((raycast_info[*i].side == 'R' || raycast_info[*i].side == 'L') && raycast_info[*i].pos.y / 100 != last.y)
			return (raycast_info[(*i) - 1].distance);
		(*i)++;
	}
	return (raycast_info[*i].distance);
}

t_blocK_wall make_one_block(t_raycast_info *raycast_info, int *i)
{
	int				i_start_value;
	t_blocK_wall	wall;

	i_start_value = *i;
	wall.start_distance = raycast_info[*i].distance;
	wall.side = raycast_info[*i].side;
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
//		if (i > 0 && ((all_wall[i].last_inpact.x == all_wall[i].first_inpact.x
//					  && (all_wall[i].first_inpact.x == all_wall[i - 1].last_inpact.x)
//					  && (all_wall[i - 1].last_inpact.x == all_wall[i - 1].first_inpact.x))
//			|| ((all_wall[i].last_inpact.y == all_wall[i].first_inpact.y)
//				&& (all_wall[i].first_inpact.y == all_wall[i - 1].last_inpact.y)
//				&& (all_wall[i - 1].last_inpact.y == all_wall[i - 1].first_inpact.y))))
//		{
//			all_wall[i - 1] = fusion_wall(all_wall[i - 1], all_wall[i]);
//			nb_fusion++;
//			i--;
//		}
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