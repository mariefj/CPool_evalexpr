#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "my.h"
#include "eval_postfix.h"
#include "eval_expr.h"
#include "my_str_to_op_array.h"
#include "my_struct_stack.h"
#include "my_struct_func_ptr.h"

#include <stdio.h>

int	my_tab_size(const char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;

	return (i);
}

static int	my_get_nbr(char const *str)
{
	int i = 0;
	int nb = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((INT_MAX - (str[i] - '0')) / 10 <= nb)
		{
			return (0);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
	{
		nb *= -1;
	}

	return (nb);
}

int	eval_postfix(const char **array_postfix)
{
	int i = 0;
	int val1 = 0;
	int val2 = 0;
	my_struct_stack_t *stack = stack_init(my_tab_size(array_postfix));

	// my_print_array(array_postfix);
	if (stack == NULL)
		return (-1);

	while (i < my_tab_size(array_postfix))
	{
		if (array_postfix[i][1] != '\0' || is_digit(array_postfix[i][0]))
		{
			push(stack, my_get_nbr(array_postfix[i]));
		}
		else
		{
			val1 = pop(stack);
			val2 = pop(stack);
			push(stack, do_op(array_postfix[i][0], val2, val1));
		}
		i++;
	}

	return (pop(stack));
}