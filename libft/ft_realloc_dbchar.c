#include "libft.h"
#include <stdlib.h>

char	**ft_realloc_dbchar(char **map, char *new_line)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_dbstrlen(map) + 2));
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i++] = new_line;
	new_map[i] = 0;
	ft_free_dbchar_tab(map, 0);
	return (new_map);
}