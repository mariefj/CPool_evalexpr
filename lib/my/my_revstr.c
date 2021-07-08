#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

static void	my_swap_char(char *a, char *b)
{
	char temp = *a;

	*a = *b;
	*b = temp;
}

char	*my_revstr(char *str)
{
	int i = 0;
	int j = my_strlen(str) - 1;

	while (i < j)
	{
		my_swap_char(&str[i], &str[j]);
		i++;
		j--;
	}

	return (str);
}