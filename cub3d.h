/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:19 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/13 18:44:38 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WITH_SCREEN 1920
# define HEIGHT_SCREEN 1080
# define LEN_CHUNCK 100
# define LEN_CHUNCK_MAP 0.01
# define PI 3.14159265359
# define FOV 100.0
# define DEGRES_PRECISION 0.1
# define LEN_RAYCAST 500000000.0
# define PlAYER_SIZE 10
# define COLLISION_EXTRA_BORDER 30
# define PLAYER_SPEED 10

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
	void			*img;
	unsigned char	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int 			width;
	int 			heigth;
}				t_img;

typedef struct s_textures {
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor;
	int		roof;
}	t_textures;

typedef struct s_coordonate
{
	int	x;
	int	y;
}	t_coordonate;

typedef struct s_coordonatef
{
	double	x;
	double	y;
} t_coordonatef;

typedef struct s_player
{
	t_coordonatef	coordonatef;
	int				rotation;
}	t_player;

typedef struct s_data
{
	char		**map;
	t_player	player;
} t_data;


typedef struct s_raycast_info
{
	char			side;
	double			distance;
	double			pos;
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
	t_textures	*textures;
	t_img		*img;
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

typedef struct s_impact_info
{
	t_data		data;
	t_window	window;
}	t_impact_info;

void				calcule_coordonate_chunck(int chunck, int *x, int *y, char **map);
int					count_nb_chunck(char **map);
void				show_map(t_img	img, char **map);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
int					quit(t_all *all);

//Parcing

char				**parsing_map(int fd);
int					map_validity(char **map);

//Setup

void				setup_mlx(t_window *window);
int					setup_textures(int fd, t_textures *textures, t_window *window);
int					setup_data(char **argv, t_textures *textures, t_data *data, t_window *window);

//Vector Utils

t_coordonatef	    rotate_vector(t_coordonatef vector, int angle);
t_coordonatef	    add_vector(t_coordonatef vector1, t_coordonatef vector2);
void	            rotate_player(t_all *all, int rotation);
int					roundFloat(float value);


//Input

int					input_handling(int keycode, t_all *all);
void				move(t_data	*data, double x, double y);
int					show_player_mini_map(t_img img, t_player player);
t_player			make_player(char **map);

//Debug

int					show_debug_map(t_all *all);

//Raycasting

t_raycast_info		*raycasting_minimap(t_data data);

//show 3dmap

void 				show_screen(t_raycast_info *ray_info, t_img img, t_textures textures);

// checkpos

t_coordonatef		check_posible_position(t_coordonatef possible, t_data data);

// display
void				show_roof_floor(t_img img, t_textures textures);

#endif