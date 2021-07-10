#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int	my_tab_size(const char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;

	return (i);
}