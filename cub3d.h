/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:19 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 11:12:49 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WITH_SCREEN 1920
# define LENGTH_SCREEN 1080
# define LEN_CHUNCK 100
# define LEN_CHUNCK_MAP 20 * WITH_SCREEN / 1920

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "fcntl.h"
# include <X11/X.h>
# include <math.h>

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

typedef struct s_player
{
	t_coordonate	coordonate;
	int				rotation;
}	t_player;

typedef struct s_data
{
	char		**map;
	t_player	player;
	
} t_data;

void		calcule_coordonate_chunck(int chunck, int *x, int *y, char **map);
int			count_nb_chunck(char **map);
void		show_map(t_img	img, char **map);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			quit(void *a);
int			show_player_mini_map(t_img img, t_player player);
t_player	make_player(char **map);

#endif