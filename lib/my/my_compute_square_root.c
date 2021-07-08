#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

int	my_compute_square_root(int nb)
{
	int i = 0;

	if (nb == 1)
	{
		return (1);
	}
	while (i * i <= nb)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}

	return(0);
}