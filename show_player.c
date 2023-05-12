#include "cub3d.h"

int	show_player_mini_map(t_img img, t_player player)
{
	int 		x;
	int 		y;
	t_coordonate codnt_player_mini;

	codnt_player_mini.x = player.coordonate.x / (LEN_CHUNCK / LEN_CHUNCK_MAP);
	codnt_player_mini.y = player.coordonate.y / (LEN_CHUNCK / LEN_CHUNCK_MAP);
	y = codnt_player_mini.y - LEN_CHUNCK_MAP / 2 + PlAYER_SIZE;
	while (y < codnt_player_mini.y + LEN_CHUNCK_MAP / 2  + PlAYER_SIZE)
	{
		x = codnt_player_mini.x - LEN_CHUNCK_MAP / 2  + PlAYER_SIZE;
		while (x < codnt_player_mini.x + LEN_CHUNCK_MAP / 2  + PlAYER_SIZE)
		{
			my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
	return (0);
}