#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

int	my_show_word_array(char * const *tab)
{
	int i = 0;

	while (tab[i] != NULL)
	{
		my_putstr(tab[i]);
		my_putchar('\n');
		i++;
	}

	return (i);
}