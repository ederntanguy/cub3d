/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:31:18 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/12 11:32:17 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coordonatef	rotate_vector(t_coordonatef vector, int angle)
{
	t_coordonatef	rotated;
	double			rad;

	rad = angle * M_PI / 180.0;
	if (vector.x == 0)
		rad *= -1;
	rotated.x = vector.x * cos(rad) - vector.y * sin(rad);
	rotated.y = vector.x * sin(rad) - vector.y * cos(rad);
	return (rotated);
}

t_coordonatef	add_vector(t_coordonatef vector1, t_coordonatef vector2)
{
	t_coordonatef	new;

	new.x = vector1.x + vector2.x;
	new.y = vector1.y + vector2.y;
	return (new);
}

int	round_float(float value)
{
	int	rounded;

	rounded = (int)(value + 0.5);
	return (rounded);
}
