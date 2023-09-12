/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:33:38 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 14:53:22 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_is_cub_file(char *name_map)
{
	int	i;

	i = 0;
	while (name_map[i])
		i++;
	if (!(i - 1 > 0 && name_map[i - 1] == 'b'))
		return (0);
	if (!(i - 2 > 0 && name_map[i - 2] == 'u'))
		return (0);
	if (!(i - 3 > 0 && name_map[i - 3] == 'c'))
		return (0);
	if (!(i - 4 > 0 && name_map[i - 4] == '.'))
		return (0);
	return (1);
}

void	free_img_texture(t_textures *textures, t_window *window)
{
	if (textures->east.img)
		mlx_destroy_image(window->mlx, textures->east.img);
	if (textures->west.img)
		mlx_destroy_image(window->mlx, textures->west.img);
	if (textures->south.img)
		mlx_destroy_image(window->mlx, textures->south.img);
	if (textures->north.img)
		mlx_destroy_image(window->mlx, textures->north.img);
}

int	check_texture_good_init(t_textures *textures, t_window *window, int where)
{
	if (textures->floor == -1 || textures->roof == -1 || !textures->south.img
		|| !textures->east.img || !textures->west.img || !textures->north.img)
	{
		if (where == 1)
		{
			free_img_texture(textures, window);
			ft_putstr_fd("Error\nDon't have all informations\n", 2);
		}
		return (0);
	}
	return (1);
}

int	setup_data(char **argv, t_textures *textures,
t_data *data, t_window *window)
{
	int	fd;

	if (!check_is_cub_file(argv[1]))
		return (ft_putstr_fd("Error\nThe file is not a .cub file\n", 2), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nFailed to open .cub\n", 2), 0);
	if (setup_textures(fd, textures, window))
		return (ft_putstr_fd("Error\nFailed to load textures or invalid .cub\n",
				2),
			0);
	if (!check_texture_good_init(textures, window, 1))
		return (0);
	data->map = parsing_map(fd);
	if (!map_validity(data->map))
		return (free_img_texture(textures, window),
			ft_free_dbchar_tab(data->map, 0), 0);
	data->player = make_player(data->map);
	return (1);
}

int	setup_mlx(t_window*window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (0);
	window->win = mlx_new_window(window->mlx, WITH_SCREEN,
			HEIGHT_SCREEN, "Hello world!");
	return (1);
}
