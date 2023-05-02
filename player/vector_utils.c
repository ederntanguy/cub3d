#include "../cub3d.h"

t_coordonate	rotate_vector(t_coordonate vector,
	t_coordonate position, int angle)
{
	t_coordonate	rotated;

	rotated.x = (vector.x - position.x) * cos(angle)
		- (position.y - vector.y) * sin(angle);
	rotated.y = (position.x - vector.x) * sin(angle)
		- (vector.y - position.y) * cos(angle);
	return (rotated);
}

t_coordonate	add_vector(t_coordonate vector1, t_coordonate vector2)
{
	t_coordonate	new;

	new.x = vector1.x + vector2.x;
	new.y = vector1.y + vector2.y;
	return (new);
}
