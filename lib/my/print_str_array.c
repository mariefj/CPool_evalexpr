#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int	print_str_array(const char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		my_putstr(array[i]);
		my_putchar('\n');
		i++;
	}

	return (i);
}