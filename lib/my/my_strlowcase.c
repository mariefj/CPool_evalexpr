#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}

	return (str);
}