#include <unistd.h>
#include <stdlib.h> // free

#include "my.h"
#include "eval_postfix.h"
#include "my_struct_stack.h"
#include "my_struct_func_ptr.h"

int	eval_postfix(const char **array_postfix)
{
	int 			i = 0;
	my_struct_stack_t	*stack = stack_init(my_tab_size(array_postfix));
	int			result;

	if (stack == NULL)
		return (-1);

	while (i < my_tab_size(array_postfix))
	{
		if (array_postfix[i][1] != '\0' || is_digit(array_postfix[i][0]))
			push(stack, my_getnbr(array_postfix[i]));
		else
			push(stack, do_op(array_postfix[i][0], pop(stack), pop(stack)));
		i++;
	}
	result = pop(stack);
	free(stack->array);
	free(stack);

	return (result);
}