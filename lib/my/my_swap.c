#include <unistd.h>
#include <stdlib.h>

#include "my.h"

void	my_swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}