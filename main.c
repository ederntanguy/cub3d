/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:18 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/12 18:06:56 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (!(x >= 0 && x <= WITH_SCREEN && y >= 0 && y <= HEIGHT_SCREEN))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_data		data;
	t_all 		all;
	t_textures	textures;

	setup_mlx(&window);
	if (setup_data(argv, &textures, &data, &window))
		return (0);
	all.data = &data;
	all.textures = &textures;
	all.window = &window;
	show_debug_map(&all);
	mlx_key_hook(window.win, input_handling, &all);
//	mlx_loop_hook(window.mlx, show_debug_map, &all);
	mlx_hook(window.win, DestroyNotify, ButtonReleaseMask, quit, NULL);
	mlx_loop(window.mlx);
}
