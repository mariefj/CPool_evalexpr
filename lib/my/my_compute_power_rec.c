#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

int	my_compute_power_rec(int nb, int p)
{
	int nbr = nb;

	if (p == 0)
	{
		return (1);
	}

	if (p < 0)
	{
		return (0);
	}

	return (nb * my_compute_power_rec(nbr, p - 1));
}