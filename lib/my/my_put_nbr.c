#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int	my_put_nbr(int nb)
{
	int count = 0;

	if (nb < 0)
	{
		my_putchar('-');
	}
	nb = my_abs(nb);
	if (nb < 10)
	{
		return (my_putchar('0' + nb));
	}
	count += my_put_nbr(nb / 10);
	count += my_putchar('0' + (nb % 10));

	return (count);
}