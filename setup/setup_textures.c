#include "../cub3d.h"

t_img	make_image(void *mlx, char *filename)
{
	t_img	img;

	filename[ft_strlen(filename) - 1] = 0;
	img.img = mlx_xpm_file_to_image(mlx, filename + 3, &(img.width), &(img.heigth));
	img.addr = (unsigned char *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
					&img.endian);
	return (img);
}

int	make_color(char *str)
{
	int ret;
	int tmp;

	ret = 0;
	tmp = 0;
	while (*str)
	{
		if (*str == ',' || *str == '\n')
		{
			ret *= 256;
			ret += tmp;
			tmp = 0;
		}
		else
		{
			tmp *= 10;
			tmp += *str - '0';
		}
		str++;
	}
	return (ret);
}

int	setup_textures(int fd, t_textures *textures, t_window *window)
{
	char *tmp;
	int	stop;

	stop = 0;
	tmp = get_next_line(fd);
	while (tmp && stop < 6)
	{
		if (ft_strncmp(tmp, "NO ", 3) == 0 && ++stop)
			textures->north = make_image(window->mlx, tmp);
		else if (ft_strncmp(tmp, "SO ", 3) == 0 && ++stop)
			textures->south = make_image(window->mlx, tmp);
		else if (ft_strncmp(tmp, "WE ", 3) == 0 && ++stop)
			textures->west = make_image(window->mlx, tmp);
		else if (ft_strncmp(tmp, "EA ", 3) == 0 && ++stop)
			textures->east = make_image(window->mlx, tmp);
		else if (ft_strncmp(tmp, "F ", 2) == 0 && ++stop)
			textures->floor = make_color(tmp + 2);
		else if (ft_strncmp(tmp, "C ", 2) == 0 && ++stop)
			textures->roof = make_color(tmp + 2);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	printf("%d \n", textures->south.addr[(9 * textures->south.line_length) + (15 * textures->south.bits_per_pixel / 8)]);
	return (0);
}
