#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "my.h"

int	my_find_prime_sup(int nb)
{
	int i = 0;

	if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11)
	{
		return (nb);
	}
	while (nb + i < INT_MAX)
	{
		if ((nb + i) % 2 == 0 || (nb + i) % 3 == 0 || (nb + i) % 5 == 0 || (nb + i) % 7 == 0 || (nb + i) % 11 == 0)
		{

		}
		else if (my_is_prime(nb + i) == 1)
		{
			return (nb + i);
		}
		i++;
	}

	return (INT_MAX);
}