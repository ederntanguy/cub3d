#include "cub3d.h"

void	init_ray(t_ray *ray, t_camera *camera, double camerax)
{
	ray->ray_dir_x = camera->dir_x + camera->plane_x * camerax;
	ray->ray_dir_y = camera->dir_y + camera->plane_y * camerax;
	ray->map_x = (int)camera->pos_x;
	ray->map_y = (int)camera->pos_y;
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (camera->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - camera->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (camera->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - camera->pos_y) * ray->delta_dist_y;
	}
}

t_raycast_info	make_dda(t_ray *ray, char **map, int x, t_camera camera)
{
	t_raycast_info ray_info;
	int hit;

	hit = 0;
	(void) camera;
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
	if (ray->side == 0)
	{
		ray_info.distance = ray->side_dist_x - ray->delta_dist_x;
		if (ray->step_x > 0)
			ray_info.side = 'E';
		else
			ray_info.side = 'W';
		ray_info.pos = camera.pos_x - tan((2 * x / (double)WITH_SCREEN - 1) * (FOV * PI / 180.0 / 2.0)) * ray_info.distance;
	}
	else
	{
		ray_info.distance = ray->side_dist_y - ray->delta_dist_y;
		if (ray->step_y > 0)
			ray_info.side = 'N';
		else
			ray_info.side = 'S';
		ray_info.pos = camera.pos_y - (tan((2 * x / (double)WITH_SCREEN - 1) * (FOV * PI / 180.0 / 2.0)) * ray_info.distance);
	}
	ray_info.pos = fmod(ray_info.pos, 1.0);
	if (ray_info.pos < 0)
		ray_info.pos++;
	return (ray_info);
}

t_raycast_info	calcule_raycast(t_data data, int x, t_camera camera)
{
	t_ray			ray;
	t_raycast_info	ray_info;
	double			camerax;

	camerax = (2.0 * (double)x) / (double)WITH_SCREEN - 1.0;
	init_ray(&ray, &camera, camerax);
	ray_info = make_dda(&ray, data.map, x, camera);
//	printf("%f %f\n", ray.side_dist_x, ray.side_dist_y);
//	printf("%f\n", ray_info.pos);
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