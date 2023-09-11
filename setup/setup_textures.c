#include "../cub3d.h"

t_img	make_image(void *mlx, char *filename)
{
	t_img	img;
	int 	i;

	i = 0;
	while (filename[i] && filename[i + 1]
		&& filename[i + 2] && filename[i + 2] == ' ')
		i++;
	filename[ft_strlen(filename) - 1] = 0;
	img.img = mlx_xpm_file_to_image(mlx,
									filename + 2 + i, &(img.width), &(img.heigth));
	if (!img.img)
		return (img);
	img.addr = (unsigned char *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
												  &img.line_length, &img.endian);
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
		else if (*str != ' ')
		{
			tmp *= 10;
			tmp += *str - '0';
		}
		str++;
	}
	return (ret);
}

void init_to_null_textures(t_textures *textures)
{
	textures->south.img = NULL;
	textures->north.img = NULL;
	textures->east.img = NULL;
	textures->west.img = NULL;
	textures->roof = -1;
	textures->floor = -1;
}

void	texture_setup_loop(char *tmp, int *stop, t_textures *te, t_window *win)
{
	int i;

	i = 0;
	while (tmp[i] && tmp[i] == ' ')
		i++;
	if (ft_strncmp(tmp + i, "NO ", 3) == 0 && ++stop)
		te->north = make_image(win->mlx, tmp + i);
	else if (ft_strncmp(tmp + i, "SO ", 3) == 0 && ++stop)
		te->south = make_image(win->mlx, tmp + i);
	else if (ft_strncmp(tmp + i, "WE ", 3) == 0 && ++stop)
		te->west = make_image(win->mlx, tmp + i);
	else if (ft_strncmp(tmp + i, "EA ", 3) == 0 && ++stop)
		te->east = make_image(win->mlx, tmp + i);
	else if (ft_strncmp(tmp + i, "F ", 2) == 0 && ++stop)
		te->floor = make_color(tmp + 2 + i);
	else if (ft_strncmp(tmp, "C ", 2) == 0 && ++stop)
		te->roof = make_color(tmp + 2 + i);
}

int	setup_textures(int fd, t_textures *textures, t_window *window)
{
	char	*tmp;
	int		stop;

	stop = 0;
	init_to_null_textures(textures);
	tmp = get_next_line(fd);
	while (tmp && stop < 6)
	{

		texture_setup_loop(tmp, &stop, textures, window);
		if (check_texture_good_init(textures, window, 0))
			break ;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (0);
}
