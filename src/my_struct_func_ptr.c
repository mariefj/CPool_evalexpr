#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_func_ptr.h"
#include "my_operation.h"

void 	set_up_struct(my_struct_func_ptr_t *ops)
{
	ops[0].op = '+';
	ops[0].operation = &my_add;

	ops[1].op = '-';
	ops[1].operation = &my_minus;

	ops[2].op = '*';
	ops[2].operation = &my_mul;

	ops[3].op = '/';
	ops[3].operation = &my_div;

	ops[4].op = '%';
	ops[4].operation = &my_mod;
}

int	is_valid_op(char op)
{
	my_struct_func_ptr_t	ops[OPERATOR_NB];
	int			i = 0;

	set_up_struct(ops);
	while (i != OPERATOR_NB)
	{
		if (ops[i].op == op)
			return (1);
		i++;
	}

	return (0);
}

int 	do_op(char op, int val1, int val2)
{
	my_struct_func_ptr_t	ops[OPERATOR_NB];
	int			i = 0;

	set_up_struct(ops);
	while (i != OPERATOR_NB)
	{
		if (ops[i].op == op)
			return (ops[i].operation(val1, val2));
		i++;
	}

	my_putstr("Bad op\n");
	exit(84);
}