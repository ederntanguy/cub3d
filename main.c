/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:18 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 14:40:40 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	unsigned char	*dst;

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
	t_img		img;

	if (argc != 2)
		return (ft_putstr_fd("Error : Invalide number of parameter\n", 2), 0);	setup_mlx(&window);
	setup_mlx(&window);
	if (!setup_data(argv, &textures, &data, &window))
		return (0);
	all.data = &data;
	all.textures = &textures;
	all.window = &window;
	all.is_show_finish = 0;
	img.img = mlx_new_image(window.mlx, 1920, 1080);
	img.addr = (unsigned char *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
												  &img.endian);
	all.img = &img;
	show_debug_map(&all);
	mlx_hook(window.win, 2, 1L<<0, input_handling, &all);
	mlx_hook(window.win, DestroyNotify, ButtonReleaseMask, quit, &all);
	mlx_loop(window.mlx);
}

