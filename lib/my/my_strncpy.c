#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strncpy(char *dest, char const *str, int n)
{
	int i = 0;

	while (str[i] != '\0' && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}