/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:29:37 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:29:38 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move(t_data	*data, double x, double y)
{
	t_coordonatef	initial_vector;
	t_coordonatef	new_position;

	initial_vector.x = x;
	initial_vector.y = y;
	initial_vector = rotate_vector(initial_vector,
			data->player.rotation);
	new_position = add_vector(initial_vector, data->player.coordonatef);
	data->player.coordonatef = check_posible_position(new_position, *data);
}

void	rotate_player(t_all *all, int rotation)
{
	all->data->player.rotation += rotation;
}
