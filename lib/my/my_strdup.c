#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

char	*my_strdup(char const *str)
{
	int i = 0;
	char *strcpy = (char *)malloc((my_strlen(str) + 1) * sizeof(char));

	if (strcpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = '\0';

	return (strcpy);
}