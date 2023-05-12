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
		pos.x = i * cos(radians) + data.player.coordonate.x + LEN_CHUNCK / 2;
		pos.y = i * sin(radians) + data.player.coordonate.y + LEN_CHUNCK / 2;
		if (is_in_wall_chunck(data, pos) == 0)
			break ;
		my_mlx_pixel_put(&img, (int)ceil(pos.x / (LEN_CHUNCK / LEN_CHUNCK_MAP)), (int)ceil(pos.y / (LEN_CHUNCK / LEN_CHUNCK_MAP)), 0x00FFFF00);
		i+=1;
	}
}

void	make_dda(t_ray *ray, char **map)
{
	int hit;

double *raycasting_minimap(t_data data, t_img img)
{
	t_raycast_info	*raycast_info;
	double			*length;
	int 			x;
	t_camera		camera;
	double 			plan_length;

	plan_length = tan((FOV * PI / 180.0) / 2);
	camera.pos_x = data.player.coordonatef.x;
	camera.pos_y = data.player.coordonatef.y;
	camera.dir_x = cos(data.player.rotation * (PI / 180));
	camera.dir_y = sin(data.player.rotation * (PI / 180));
	camera.plane_x = -camera.dir_y * plan_length;
	camera.plane_y = camera.dir_x * plan_length;
//	(void) img;
//	(void) data;
//	(void) camera;
	x = 0;
	raycast_info = malloc(sizeof(t_raycast_info) * (WITH_SCREEN + 2));
	length = malloc(sizeof(double) * (WITH_SCREEN + 1));
	raycast_info[WITH_SCREEN].distance = -1;
	while (x < WITH_SCREEN)
	degres = (float)(data.player.rotation) - FOV / 2.0;
 
	while (degres < (float)(data.player.rotation) + FOV / 2.0)
	{
		calcul_draw_line(degres, data, img);
		degres+=0.1;
=======
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
>>>>>>> relou
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

double	calcule_raycast(t_data data, t_img img, int x, t_camera camera)
{
	t_ray		ray;
	double		camerax;

//	(void) data;
	(void) img;

	camerax = (2.0 * (double)x) / (double)WITH_SCREEN - 1.0;
	init_ray(&ray, &camera, camerax);
	make_dda(&ray, data.map);
	return (ray.perp_wall_dist);
}

double *raycasting_minimap(t_data data, t_img img)
{
	t_raycast_info	*raycast_info;
	double			*length;
	int 			x;
	t_camera		camera;
	double 			plan_length;

	plan_length = tan((FOV * PI / 180.0) / 2);
	camera.pos_x = data.player.coordonatef.x;
	camera.pos_y = data.player.coordonatef.y;
	camera.dir_x = cos(data.player.rotation * (PI / 180));
	camera.dir_y = sin(data.player.rotation * (PI / 180));
	camera.plane_x = -camera.dir_y * plan_length;
	camera.plane_y = camera.dir_x * plan_length;
//	(void) img;
//	(void) data;
//	(void) camera;
	x = 0;
	raycast_info = malloc(sizeof(t_raycast_info) * (WITH_SCREEN + 2));
	length = malloc(sizeof(double) * (WITH_SCREEN + 1));
	raycast_info[WITH_SCREEN].distance = -1;
	while (x < WITH_SCREEN)
	{
		if (x == 1766)
			printf("f");
		length[x] = calcule_raycast(data, img, x, camera);
		x++;
	}
	return (length);
}