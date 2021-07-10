#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "eval_expr.h"
#include "my_struct_stack.h"
#include "my_struct_func_ptr.h"
#include "my_str_to_op_array.h"
#include "infix_to_postfix.h"
#include "eval_postfix.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		my_put_nbr(eval_expr(av[1]));
		my_putchar('\n');

		return (0);
	}

	return (0);
}
