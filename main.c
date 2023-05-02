/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carv <gde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:18 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 13:14:20 by gde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

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
	t_window	window;
	t_data		data;

	(void) argc;
	data = setup_data(argv);
	window = setup_mlx(&data);
	show_debug_map(&data, &window);
	ft_free_dbchar_tab(data.map, 0);
}
