#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int	my_abs(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
	}

	return (nb);
}