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

t_each_wall_pos *add_wall(t_each_wall_pos *all_wall_tab, int it_start, int it_end)
{
	int				i;
	int 			j;

	j = 0;
	t_each_wall_pos *new;
	i = 0;
	while (all_wall_tab[i].pos_it_end != -1)
		i++;
	new = malloc(sizeof(t_each_wall_pos) * (i + 2));
	while (i > j)
	{
		new[j].pos_it_end = all_wall_tab[j].pos_it_end;
		new[j].pos_it_start = all_wall_tab[j].pos_it_start;
		j++;
	}
	new[j].pos_it_start = it_start;
	new[j].pos_it_end = it_end;
	new[j + 1].pos_it_end = -1;
	return (free(all_wall_tab), new);
}

t_each_wall_pos *find_all_wall_separatio(int i_start_value, int *i, t_raycast_info *raycast_info)
{
	int				start;
	int 			last_chunck;
	t_each_wall_pos	*all_wall_tab;

	all_wall_tab = malloc(sizeof(t_each_wall_pos));
	all_wall_tab[0].pos_it_end = -1;
	last_chunck = raycast_info[i_start_value].pos.x / 100 * 10000000 + raycast_info[i_start_value].pos.y / 100;
	start = i_start_value;
	while (i_start_value <= *i)
	{
		if (last_chunck != raycast_info[i_start_value].pos.x / 100 * 10000000 + raycast_info[i_start_value].pos.y / 100)
		{
			all_wall_tab = add_wall(all_wall_tab, start, i_start_value);
			start = i_start_value;
			last_chunck = raycast_info[i_start_value].pos.x / 100 * 10000000 + raycast_info[i_start_value].pos.y / 100;
		}
		i_start_value++;
	}
	return (all_wall_tab);
}

t_blocK_wall make_one_block(t_raycast_info *raycast_info, int *i)
{
	int				i_start_value;
	t_blocK_wall	wall;

	i_start_value = *i;
	wall.start_distance = raycast_info[*i].distance;
	wall.end_distance = get_end_wall(raycast_info, i);
	wall.last_inpact = raycast_info[*i - 1].pos;
	wall.first_inpact = raycast_info[i_start_value].pos;
	wall.wall_len = *i - i_start_value;
	wall.each_wall = find_all_wall_separatio(i_start_value, i, raycast_info);
	return (wall);
}

t_each_wall_pos *fusion_tab_wall(t_each_wall_pos *first, t_each_wall_pos *last)
{
	t_each_wall_pos	*new;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (first[i].pos_it_end != -1)
		i++;
	while (last[k++].pos_it_end != -1)
		i++;
	k = 0;
	new = malloc(sizeof(t_each_wall_pos) * (i + 1));
	while (first[j].pos_it_end != -1)
	{
		new[j].pos_it_end = first[j].pos_it_end;
		new[j].pos_it_start = first[j].pos_it_start;
		j++;
	}
	while (last[k].pos_it_end != -1)
	{
		new[j].pos_it_end = last[k].pos_it_end;
		new[j++].pos_it_start = last[k++].pos_it_start;
	}
	new[j].pos_it_end = -1;
	return (free(first), free(last), new);
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
	new.each_wall = fusion_tab_wall(first.each_wall, last.each_wall);
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