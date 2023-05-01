#include "libft.h"

int	ft_dbstrlen(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}