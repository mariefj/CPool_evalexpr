#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "my.h"

static int	my_showstr_dot(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			my_putchar('.');
		}
		else
		{
			my_putchar(str[i]);
		}
		i++;
	}

	return (0);
}

static void	my_put_space(int size)
{
	int i = size;

	while (i < 16)
	{
		if (i % 2 == 0)
		{
			my_putchar(' ');
		}
		my_putchar(' ');
		my_putchar(' ');
		i++;
	}
	my_putchar(' ');
}

int	my_showmem(char const *str, int size)
{
	int i = 0;

	my_showaddr(str);
	my_putchar(' ');
	while (i < size)
	{
		if (i % 2 == 0)
		{
			my_putchar(' ');
		}
		if (str[i] < 16)
		{
			my_putchar('0');
		}
		my_putnbr_base(str[i], "0123456789abcdef");
		i++;
	}
	my_put_space(size);
	my_showstr_dot(str);

	return (0);
}