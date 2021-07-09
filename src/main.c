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




	/**** TEST STRUCT_STACK ****/

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
	// my_putchar('\n');
	// my_put_nbr(is_empty(stack));


	/**** TEST STRUCT_FUNC_PTR / DO_OP ****/

	//my_put_nbr(do_op('-', 10, 3));

	// char const *array_infix[] = {"0", "+", "-5", "*", "(", "(", "302", "-", "300", ")", "%", "2", ")"};
	// char **array_postfix = infix_to_postfix(array_infix, 12);


	/**** INFIX_TO_POSTFIX ****/

	// my_putstr(array_postfix[0]);
	// my_putchar(' ');
	// my_putstr(array_postfix[1]);
	// my_putchar(' ');
	// my_putstr(array_postfix[2]);
	// my_putchar(' ');
	// my_putstr(array_postfix[3]);
	// my_putchar(' ');
	// my_putstr(array_postfix[4]);
	// my_putchar(' ');
	// my_putstr(array_postfix[5]);
	// my_putchar(' ');
	// my_putstr(array_postfix[6]);
	// my_putchar(' ');
	// my_putstr(array_postfix[7]);
	// my_putchar(' ');
	// my_putstr(array_postfix[8]);
	// my_putchar('\n');

	// my_put_nbr(eval_postfix((const char **)array_postfix));

	// free(array_postfix);

	// char **array = my_str_to_op_array(str);

	// my_print_array((const char **)array);

	return (0);
}
