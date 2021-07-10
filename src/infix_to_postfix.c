#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "utils_infix_to_postfix.h"
#include "infix_to_postfix.h"
#include "my_str_to_op_array.h"
#include "my_struct_stack.h"

static void 	truc3(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
{
	if (array_infix[i][0] == ')')
	{
		while (!is_empty(stack) && peek(stack) != '(')
		{
			push_array(array_postfix, op_to_str(pop(stack)));
		}
		pop(stack);
	}
	else
	{
		while (!is_empty(stack) && get_precedence(array_infix[i][0]) <= get_precedence(peek(stack)))
		{
			push_array(array_postfix, op_to_str(pop(stack)));
		}
		push(stack, array_infix[i][0]);
	}
}

static void 	truc2(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
{
	if (array_infix[i][1] != '\0' || is_digit(array_infix[i][0]))
		push_array(array_postfix, array_infix[i]);
	else if (array_infix[i][0] == '(')
		push(stack, (int)array_infix[i][0]);
}

static void 	truc(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
{
	if (array_infix[i][1] != '\0' || is_digit(array_infix[i][0]) || array_infix[i][0] == '(')
		truc2(array_infix, array_postfix, stack, i);
	else
		truc3(array_infix, array_postfix, stack, i);
}

char	**infix_to_postfix(char const **array_infix, int size)
{
	int i = 0;
	my_struct_stack_t *stack = stack_init(size);
	char **array_postfix = create_str_array(size + 1);

	array_postfix[0] = NULL;
	while (i < size)
	{
		truc(array_infix, array_postfix, stack, i);
		i++;
	}
	while (!is_empty(stack))
	{
		push_array(array_postfix, op_to_str(pop(stack)));
		i++;
	}
	free(stack);

	return (array_postfix);
}
