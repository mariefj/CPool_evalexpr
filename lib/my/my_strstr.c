#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strstr(char *str, char const *to_find)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0' && to_find[j] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		i++;
	}
	if (j == my_strlen(to_find))
	{
		return (&str[i - j]);
	}

	return (NULL);
}