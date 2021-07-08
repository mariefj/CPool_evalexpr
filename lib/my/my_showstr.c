#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "my.h"

int	my_showstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			my_putchar('\\');
			if (str[i] < 16)
			{
				my_putchar('0');
			}
			my_putnbr_base(str[i], "0123456789abcdef");
		}
		else
		{
			my_putchar(str[i]);
		}
		i++;
	}

	return (0);
}