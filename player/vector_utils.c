#include "../cub3d.h"

t_coordonate	rotate_vector(t_coordonate vector,
	t_coordonate position, int angle)
{
	t_coordonate	rotated;
	double			rad;

	rad = angle * M_PI / 180.0;
	rotated.x = vector.x * cos(rad) - vector.y * sin(rad);
	rotated.y = vector.x * sin(rad) - vector.y * cos(rad);
	return (rotated);
}

t_coordonate	add_vector(t_coordonate vector1, t_coordonate vector2)
{
	t_coordonate	new;

	new.x = vector1.x + vector2.x;
	new.y = vector1.y + vector2.y;
	return (new);
}
