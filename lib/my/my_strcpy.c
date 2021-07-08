#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strcpy(char *dest, char const *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}

	return (dest);
}