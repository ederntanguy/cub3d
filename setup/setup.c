#include "../cub3d.h"

char	**parsing_map(int fd)
{
	char	**map;
	char	*tmp;

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

int	setup_data(char **argv, t_textures *textures, t_data *data, t_window *window)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (setup_textures(fd, textures, window))
		return (0);
	data->map = parsing_map(fd);
	data->player = make_player(data->map);
	return (1);
}

void	setup_mlx(t_window*window)
{

	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 1920, 1080, "Hello world!");
}