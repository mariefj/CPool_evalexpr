#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#include "my.h"

static void	my_put_zero(int nb)
{
	int i = 0;

	while (i < nb)
	{
		my_putchar('0');
		i++;
	}
}

static int	my_putnbr_hexa_addr(uintptr_t nbr)
{
	int i = 0;
	char str[64];
	char base[] = "0123456789abcdef";

	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	my_put_zero(8 - my_strlen(str));

	return (my_putstr(my_revstr(str)));
}

int	my_showaddr(char const *str)
{
	uintptr_t addr = (uintptr_t)&str[0];

	return (my_putnbr_hexa_addr(addr));
}