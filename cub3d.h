/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:19 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/12 12:29:53 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WITH_SCREEN 1920
# define LENGTH_SCREEN 1080
# define LEN_CHUNCK 100
# define LEN_CHUNCK_MAP 20 * WITH_SCREEN / 1920
# define PI 3.14159265359
# define FOV 90.0
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

typedef struct s_all
{
	t_data		data;
	t_window	window;
}	t_all;

void				calcule_coordonate_chunck(int chunck,
						int *x, int *y, char **map);
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
void				raycasting_minimap(t_data data, t_img img);
void				rotate_player(t_all *all, int rotation);

//Debug

void				show_debug_map(t_data *data, t_window *window);

#endif