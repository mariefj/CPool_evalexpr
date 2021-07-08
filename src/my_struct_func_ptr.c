#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_func_ptr.h"
#include "my_operand.h"

void set_up_struct(my_struct_func_ptr_t *ops)
{
	ops[0].op = '+';
	ops[0].operand = &my_add;

	ops[1].op = '-';
	ops[1].operand = &my_minus;

	ops[2].op = '*';
	ops[2].operand = &my_mul;

	ops[3].op = '/';
	ops[3].operand = &my_div;

	ops[4].op = '%';
	ops[4].operand = &my_mod;
}

int do_op(char op, int val1, int val2)
{
	my_struct_func_ptr_t	ops[OPERTOR_NB];
	int			i = 0;

	set_up_struct(ops);
	while (i != OPERTOR_NB)
	{
		if (ops[i] == op)
			return (ops[i].operand(val1, val2));
		i++;
	}

	my_putstr("Bad op\n");
	exit(84);
}