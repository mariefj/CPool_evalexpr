#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strcapitalize(char *str)
{
	int i = 0;
	int first_letter = 1;

	while (str[i] != '\0')
	{
		if (first_letter == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - ('a' - 'A');
			}
			first_letter = 0;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + ('a' - 'A');
			}
			if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9'))
			{
				first_letter = 1;
			}
		}
		i++;
	}

	return (str);
}