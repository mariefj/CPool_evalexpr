#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "eval_expr.h"
#include "my_struct_stack.h"
#include "my_struct_func_ptr.h"
#include "my_str_to_op_array.h"
#include "infix_to_postfix.h"
#include "eval_postfix.h"

void	my_print_array(const char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		my_putstr(array[i]);
		my_putchar('\n');
		i++;
	}
}

int	eval_expr(char *str)
{
	char **array_infix = my_str_to_op_array(str);
	char **array_postfix = infix_to_postfix((const char **)array_infix, my_tab_size((const char **)array_infix));
	int result = eval_postfix((const char **)array_postfix);

	return (result);

}