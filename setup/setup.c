#include "../cub3d.h"

char	**parsing_map(int fd)
{
	char	**map;
	char	*tmp;

	map = malloc(sizeof(char *) * 1);
	map[0] = 0;
	tmp = get_next_line(fd);
	while (tmp && *tmp)
	{
		map = ft_realloc_dbchar(map, tmp);
		tmp = get_next_line(fd);
	}
	return (map);
}

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

int	setup_data(char **argv, t_textures *textures, t_data *data, t_window *window)
{
	int	fd;

	if (!check_is_cub_file(argv[1]))
		return (ft_putstr_fd("The file is not a .cub file\n", 2), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Failed to open .cub\n", 2), 0);
	if (setup_textures(fd, textures, window))
		return (ft_putstr_fd("Failed to load textures or invalid .cub\n", 2), 0);
	data->map = parsing_map(fd);
	if (!map_validity(data->map))
		return (ft_free_dbchar_tab(data->map, 0), 0);
	data->player = make_player(data->map);
	return (1);
}

void	setup_mlx(t_window*window)
{

	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 1920, 1080, "Hello world!");
}