#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "my.h"

int	my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((INT_MAX - (str[i] - '0')) / 10 <= nb)
		{
			return (0);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
	{
		nb *= -1;
	}

	return (nb);
}