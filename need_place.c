/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:39:14 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:39:20 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**parsing_map(int fd)
{
	char	**map;
	char	*tmp;

	map = malloc(sizeof(char *) * 1);
	map[0] = 0;
	tmp = get_next_line(fd);
	while (tmp && *tmp)
	{
		map = ft_realloc_dbchar(map, tmp);
		tmp = get_next_line(fd);
	}
	return (map);
}

void	init_ray(t_ray *r, t_camera *camera)
{
	r->map_x = (int)camera->pos_x;
	r->map_y = (int)camera->pos_y;
	r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (camera->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - camera->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (camera->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - camera->pos_y) * r->delta_dist_y;
	}
}

int	empty(char c)
{
	if (c == ' ' || c == 0 || c == '\n')
		return (1);
	return (0);
}
