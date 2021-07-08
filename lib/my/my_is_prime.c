#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

int	my_near_root(int nb)
{
	int i = 0;

	if (nb == 1)
	{
		return (1);
	}
	while (i * i <= nb)
	{
		i++;
	}

	return(i);
}

int	my_is_prime(int nb)
{
	int i = 2;
	int limit = my_near_root(nb);

	if (nb < 2)
	{
		return (0);
	}
	while (nb > 1 && i < limit)
	{
		if (nb % i == 0)
		{
			return(0);
		}
		i++;
	}

	return(1);
}