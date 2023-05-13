/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:29:15 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 10:29:16 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcule_coordonate_chunck(int chunck, int *x, int *y, char **map)
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
	int	i;
	int	j;
	int	nb;

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

void	show_map(t_img	img, char **map)
{
	t_coordonate	pix_pos;
	t_coordonate	pos;
	int				chunck;

	pos.y = 0;
	chunck = 0;
	while (map[pos.y])
	{
		if (chunck >= count_nb_chunck(map))
			break ;
		calcule_coordonate_chunck(chunck, &(pos.x), &(pos.y), map);
		if (map[pos.y][pos.x] == '1')
		{
			pix_pos.y = pos.y * LEN_CHUNCK_MAP;
			while (pix_pos.y < LEN_CHUNCK_MAP + pos.y * LEN_CHUNCK_MAP)
			{
				pix_pos.x = pos.x * LEN_CHUNCK_MAP;
				while (pix_pos.x < LEN_CHUNCK_MAP + pos.x * LEN_CHUNCK_MAP)
					my_mlx_pixel_put(&img, pix_pos.x++, pix_pos.y, 0xFFFF00);
				pix_pos.y++;
			}
		}
		chunck++;
	}
}
