#include <unistd.h>
#include <stdlib.h>

#include "my.h"

int	is_digit(char digit)
{
	return ((digit >= '0' && digit <= '9'));
}