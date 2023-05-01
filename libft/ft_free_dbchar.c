#include "libft.h"
#include <stdlib.h>

int	ft_free_dbchar_tab(char **str, int size)
{
	int	i;

	i = size;
	if (i == 0)
		i = ft_dbstrlen(str) - 1;
	while (i >= 0 && str[i])
		free(str[i--]);
	free(str);
	str = NULL;
	return (0);
}