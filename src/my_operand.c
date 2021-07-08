#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_func_ptr.h"
#include "my_operand.h"

int	my_add(int val1, int val2)
{
	return (val1 + val2);
}

int	my_minus(int val1, int val2)
{
	return (val1 - val2);
}

int	my_mul(int val1, int val2)
{
	return (val1 * val2);
}

int	my_div(int val1, int val2)
{
	if (val2 != 0)
	{
		return (val1 / val2);
	}
	my_putstr("Stop: division by zero\n");

	exit(84);
}

int	my_mod(int val1, int val2)
{
	if (val2 != 0)
	{
		return (val1 % val2);
	}
	my_putstr("Stop: modulo by zero\n");

	exit(84);
}
