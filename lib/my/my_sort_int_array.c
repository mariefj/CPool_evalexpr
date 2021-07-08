#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

void	my_sort_int_array(int *array, int size)
{
	int i = 0;
	int j = 0;
	int temp;

	while (i < size)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
		i++;
	}
}