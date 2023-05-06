#include "cub3d.h"

int	show_player_mini_map(t_img img, t_player player)
{
	int 		x;
	int 		y;
	t_coordonate codnt_player_mini;

	codnt_player_mini.x = player.coordonatef.x;
	codnt_player_mini.y = player.coordonatef.y;
	y = codnt_player_mini.y - LEN_CHUNCK_MAP / 2;
	while (y < codnt_player_mini.y + LEN_CHUNCK_MAP / 2)
	{
		x = codnt_player_mini.x - LEN_CHUNCK_MAP / 2;
		while (x < codnt_player_mini.x + LEN_CHUNCK_MAP / 2)
		{
			my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
	return (0);
}