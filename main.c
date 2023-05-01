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

void calcule_coordonate_chunck(int chunck, int *x, int *y, char **map)
{
	*x = 0;
	*y = 0;
	while (chunck)
	{
		if (chunck >= (ft_strlen(map[*y]) - 1))
		{
			*y += 1;
			chunck -= (ft_strlen(map[(*y) - 1]) - 1);
		}
		else
		{
			*x += chunck;
			chunck = 0;
		}
	}
}

int	count_nb_chunck(char **map)
{
	int i;
	int j;
	int nb;

	nb = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

void	show_map(t_data	img, void *mlx, void *mlx_win, char **map)
{
	int pix_y;
	int pix_x;
	int x;
	int y;
	int chunck;

	y = 0;
	chunck = 0;
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (map[y])
	{
		if (chunck >= count_nb_chunck(map))
			break ;
		calcule_coordonate_chunck(chunck, &x, &y, map);
		if (map[y][x] == '1')
		{
			printf("pos (%d; %d)\n", y, x);
			pix_y = y * LEN_CHUNCK_MAP;
			while (pix_y < LEN_CHUNCK_MAP + y * LEN_CHUNCK_MAP)
			{
				pix_x = x * LEN_CHUNCK_MAP;
				while (pix_x < LEN_CHUNCK_MAP + x * LEN_CHUNCK_MAP)
				{
					my_mlx_pixel_put(&img, pix_x, pix_y, 0x00FF0000);
					pix_x++;
				}
				pix_y++;
			}
		}
		chunck++;
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
	void	*mlx_win;
	t_data	img;
	char **map;

	map = parsing_map(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	show_map(img,mlx,mlx_win,map);
	ft_free_dbchar_tab(map, 0);
	mlx_loop(mlx);
}