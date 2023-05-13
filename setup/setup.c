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

int	setup_data(char **argv, t_textures *textures, t_data *data, t_window *window)
{
	int	fd;

	(void) textures;
	(void) window;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Failed to open .cub\n", 2), 0);
	if (setup_textures(fd, textures, window))
		return (ft_putstr_fd("Failed to load textures or invalid .cub\n", 2), 0);
	data->map = parsing_map(fd);
	if (!map_validity(data->map))
		return (ft_putstr_fd("Failed to load textures or invalid .cub\n", 2), 0);
	data->player = make_player(data->map);
	return (1);
}

void	setup_mlx(t_window*window)
{

	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 1920, 1080, "Hello world!");
}