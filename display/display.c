/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:26:28 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:59:44 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	return_side_texture(char side, t_textures textures)
{
	if (side == 'N')
		return (textures.north);
	else if (side == 'S')
		return (textures.south);
	else if (side == 'E')
		return (textures.east);
	else if (side == 'W')
		return (textures.west);
	return (textures.east);
}

int	have_color_value(t_img side_texture, int x, int y)
{
	int	color;
	int	pos_color;

	pos_color = (y * side_texture.line_length)
		+ (x * side_texture.bits_per_pixel / 8);
	color = side_texture.addr[pos_color];
	color += side_texture.addr[pos_color + 1] * 256;
	color += side_texture.addr[pos_color + 2] * 256 * 256;
	return (color);
}

void	make_colum_color(t_img img, int pos_x, t_raycast_info ray,
t_textures textures)
{
	int		y;
	int		color;
	int		height;
	t_img	side_texture;

	side_texture = return_side_texture(ray.side, textures);
	color = 0;
	height = HEIGHT_SCREEN / ray.distance;
	y = (HEIGHT_SCREEN - height) / 2;
	while (y < HEIGHT_SCREEN - (HEIGHT_SCREEN - height) / 2)
	{
		color = have_color_value(side_texture,
				(int)(ray.pos * side_texture.width),
				(int)((y - ((HEIGHT_SCREEN - height) / 2))
					* side_texture.heigth / height));
		my_mlx_pixel_put(&img, pos_x, y, color);
		y++;
	}
}

void	show_screen(t_raycast_info *ray_info, t_img img, t_textures textures)
{
	int	i;

	i = 0;
	while (i < WITH_SCREEN)
	{
		make_colum_color(img, i, ray_info[i], textures);
		i++;
	}
}
