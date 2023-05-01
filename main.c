#include "cub3d.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	show_pixel(t_data	img, void *mlx, void *mlx_win)
{
	int i;
	int j;

	i = 0;
	j = 0;
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (i < 1000)
	{
		while (j < 1000)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

char	**realloc_dbchar(char **map, char *new_line)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_dbstrlen(map) + 2));
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i++] = new_line;
	new_map[i] = 0;
	ft_free_dbchar_tab(map, 0);
	return (new_map);
}

char **parsing_map(char *argv)
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
		map = realloc_dbchar(map, tmp);
		tmp = get_next_line(fd);
	}
	return map;
}

int	main(int argc, char **argv)
{
	(void) argc;
	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
	char **map;

	map = parsing_map(argv[1]);
	mlx = mlx_init();
	int i = 0;
	while (map[i])
	{
		printf("%s", map[i++]);
	}
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	ft_free_dbchar_tab(map, 0);
	mlx_loop(mlx);
}