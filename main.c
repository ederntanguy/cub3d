/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:18 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 11:13:13 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (!(x >= 0 && x <= WITH_SCREEN && y >= 0 && y <= LENGTH_SCREEN))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

char	**parsing_map(char *argv)
{
	char	**map;
	int		fd;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	map = malloc(sizeof(char *) * 1);
	map[0] = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		map = ft_realloc_dbchar(map, tmp);
		tmp = get_next_line(fd);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_data data;

	(void) argc;
	data.map = parsing_map(argv[1]);
	data.player = make_player(data.map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	show_map(img, data.map);
	show_player_mini_map(img, data.player);
	raycasting_minimap(data, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	ft_free_dbchar_tab(data.map, 0);
	mlx_hook(mlx_win, DestroyNotify, ButtonReleaseMask, quit, NULL);
	mlx_loop(mlx);
}
