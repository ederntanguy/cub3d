#include "../cub3d.h"

t_data	setup_data(char **argv)
{
	t_data	data;

	data.map = parsing_map(argv[1]);
	data.player = make_player(data.map);
	return (data);
}

t_window	setup_mlx(t_data *data)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(window.mlx, input_handling, data);
	mlx_hook(window.mlx, DestroyNotify, ButtonReleaseMask, quit, NULL);
	mlx_loop(window.mlx);
	return (window);
}