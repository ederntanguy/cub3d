#include "cub3d.h"

void	have_side_distance_impact(t_raycast_info *ray_info, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray_info->distance = ray->side_dist_x - ray->delta_dist_x;
		if (ray->step_x > 0)
			ray_info->side = 'E';
		else
			ray_info->side = 'W';
	}
	else
	{
		ray_info->distance = ray->side_dist_y - ray->delta_dist_y;
		if (ray->step_y > 0)
			ray_info->side = 'N';
		else
			ray_info->side = 'S';
	}
}

void	find_hit_position(t_ray *ray, char **map)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

t_raycast_info	make_dda(t_ray *ray, char **map, t_camera camera)
{
	t_raycast_info ray_info;
	double wall_hit_x;
	double wall_hit_y;

	find_hit_position(ray, map);
	have_side_distance_impact(&ray_info, ray);
	wall_hit_x = camera.pos_x + ray_info.distance * ray->ray_dir_x;
	wall_hit_y = camera.pos_y +  ray_info.distance * ray->ray_dir_y;
	if (ray->side == 0)
		ray_info.pos = wall_hit_y - floor(wall_hit_y);
	else
		ray_info.pos = wall_hit_x - floor(wall_hit_x);
	return (ray_info);
}

t_raycast_info	calcule_raycast(t_data data, int x, t_camera camera)
{
	t_ray			ray;
	t_raycast_info	ray_info;
	double			camerax;

	camerax = (2.0 * (double)x) / (double)WITH_SCREEN - 1.0;
	ray.ray_dir_x = camera.dir_x + camera.plane_x * camerax;
	ray.ray_dir_y = camera.dir_y + camera.plane_y * camerax;
	init_ray(&ray, &camera);
	ray_info = make_dda(&ray, data.map, camera);
	return (ray_info);
}

t_raycast_info *raycasting_minimap(t_data data)
{
	t_raycast_info	*ray_info;
	int 			x;
	t_camera		camera;
	double 			plan_length;

	plan_length = tan((FOV * PI / 180.0) / 2);
	camera.pos_x = (data.player.coordonatef.x + PlAYER_SIZE / 2) / 100.0;
	camera.pos_y = (data.player.coordonatef.y + PlAYER_SIZE / 2)/ 100.0;
	camera.dir_x = cos(data.player.rotation * (PI / 180));
	camera.dir_y = sin(data.player.rotation * (PI / 180));
	camera.plane_x = -camera.dir_y * plan_length;
	camera.plane_y = camera.dir_x * plan_length;
	ray_info = malloc(sizeof(t_raycast_info) * (WITH_SCREEN + 1));
	ray_info[WITH_SCREEN].distance = -1;
	x = 0;
	while (x < WITH_SCREEN)
	{
		ray_info[x] = calcule_raycast(data, x, camera);
		x++;
	}
	return (ray_info);
}