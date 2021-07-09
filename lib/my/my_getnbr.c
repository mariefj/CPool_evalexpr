#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "my.h"

int	my_get_start_index(char const *str)
{
	int i = 0;

	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		i++;
	}

	return (i);
}

int	my_getnbr(char const *str)
{
	int i = 0;
	int start = 0;
	int nb = 0;

	i = my_get_start_index(str);
	start = i - 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((INT_MAX - (str[i] - '0')) / 10 <= nb)
		{
			return (0);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	#include <stdio.h>
	printf("for str=%s => str[%d] = %c\n", str, start, str[start]);
	if (str[start] == '-')
	{
		nb *= -1;
	}

	return (nb);
}