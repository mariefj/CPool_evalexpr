#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "eval_expr.h"
#include "my_struct_stack.h"
#include "my_struct_func_ptr.h"

int	main(int ac, char **av)
{
	// if (ac == 2)
	// {
	// 	my_put_nbr(eval_expr(av[1]));
	// 	my_putchar('\n');

	// 	return (0);
	// }


	ac++;
	av++;

	// my_struct_stack_t *stack = stack_init(10);
	// push(stack, 2);
	// push(stack, 42);
	// push(stack, -10);
	// my_put_nbr(stack->array[0]);
	// my_putchar('\n');
	// my_put_nbr(stack->array[1]);
	// my_putchar('\n');
	// my_put_nbr(pop(stack));
	// my_putchar('\n');
	// my_put_nbr(peek(stack));

	//my_put_nbr(do_op('-', 10, 3));

	return (84);
}
