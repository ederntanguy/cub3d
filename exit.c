/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:03:24 by etanguy           #+#    #+#             */
/*   Updated: 2023/05/02 11:03:25 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(t_all *all)
{
	mlx_destroy_image(all->window->mlx, all->img->img);
//	mlx_destroy_image(all->window->mlx, &(all->textures->east.img));
//	mlx_destroy_image(all->window->mlx, &(all->textures->west.img));
//	mlx_destroy_image(all->window->mlx, &(all->textures->south.img));
//	mlx_destroy_image(all->window->mlx, &(all->textures->north.img));
	mlx_destroy_window(all->window->mlx, all->window->win);
	mlx_destroy_display(all->window->mlx);
	free(all->window->mlx);
	ft_free_dbchar_tab(all->data->map, 0);
	exit(EXIT_SUCCESS);
}
