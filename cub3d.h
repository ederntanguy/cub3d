/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:19 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/12 14:37:05 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WITH_SCREEN 1920
# define HEIGHT_SCREEN 1080
# define LEN_CHUNCK 1
# define LEN_CHUNCK_MAP 0.01
# define PI 3.14159265359
# define FOV 100.0
# define DEGRES_PRECISION 0.1
# define LEN_RAYCAST 500000.0
# define PlAYER_SIZE 10
# define PLAYER_SPEED 100

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coordonate
{
	int	x;
	int	y;
}	t_coordonate;



typedef struct s_coordonatef
{
	double	x;
	double	y;
}	t_coordonatef;

typedef struct s_player
{
	t_coordonate	coordonatef;
	t_coordonatef	coordonate;
	int				rotation;
}	t_player;

typedef struct s_data
{
	char		**map;
	t_player	player;

}	t_data;

typedef struct s_impact_info
{
	t_data		data;
	t_window	window;
}	t_impact_info;

typedef struct s_raycast_info
{
	char			side;
	float			distance;
	t_coordonate	pos;
} t_raycast_info;

typedef struct s_camera{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_y;
	double plane_x;
} t_camera;

typedef struct s_ray{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int 	step_y;
	int		side; // 0 for X-side, 1 for Y-side
	double ray_dir_x;
	double ray_dir_y;} t_ray;

typedef struct s_all
{
	t_data		*data;
	t_window	*window;
} t_all;

typedef struct s_each_wall_pos
{
	int	pos_it_start;
	int	pos_it_end;
}	t_each_wall_pos;

typedef struct s_blocK_wall
{
	char			side;
	double			start_distance;
	double			end_distance;
	double			wall_len;
	double			pourcentage_of_screen;
	int				pos_x_start;
	int				pos_x_end;
	int				height_start;
	int				height_end;
	t_coordonate	first_inpact;
	t_coordonate	last_inpact;

} t_blocK_wall;

void				calcule_coordonate_chunck(int chunck, int *x, int *y, char **map);
int					count_nb_chunck(char **map);
void				show_map(t_img	img, char **map);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
int					quit(void *a);

//Parcing

char				**parsing_map(char *argv);

//Setup

void				setup_mlx(t_window *window);
t_data				setup_data(char **argv);

//Vector Utils

t_coordonatef		check_posible_position(t_coordonatef possible, t_data data);
t_coordonatef		rotate_vector(t_coordonatef vector, int angle);
t_coordonatef		add_vector(t_coordonatef vector1, t_coordonatef vector2);
int 				roundFloat(float value);

//Input

int					input_handling(int keycode, t_all *all);
void				move(t_data	*data, double x, double y);
int					show_player_mini_map(t_img img, t_player player);
t_player			make_player(char **map);
void				rotate_player(t_all *all, int rotation);

//Debug

int					show_debug_map(t_all *all);

//Raycasting

double				*raycasting_minimap(t_data data, t_img img);

//show 3dmap

t_blocK_wall		*creat_wall_array(t_data data, t_img img, t_raycast_info *raycast_info);
void 				show_screen(double *all_wall, t_img img);

#endif