#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "infix_to_postfix.h"
#include "my_str_to_op_array.h"
#include "my_struct_stack.h"
#include "eval_postfix.h"
#include "eval_expr.h"

int	get_precedence(char op)
{
	if (op == '+' || op == '-')
		return (1);

	if (op == '*' || op == '/' || op == '%')
		return (2);

	return (-1);
}

char	**create_array_postfix(int size)
{
	char **array = (char **)malloc(size * sizeof(char *));
	if (array == NULL)
		exit(84);

	return (array);
}

char	*op_to_str(int op)
{
	char *op_str = (char *)malloc(2 * sizeof(char));

	if (op_str == NULL)
		return (NULL);

	op_str[0] = (char)op;
	op_str[1] = '\0';

	return (op_str);
}

void	push_array(char **array, const char *elem)
{
	int i = my_tab_size((const char **)array);

	array[i] = my_strdup(elem);
	array[i + 1] = NULL;
}

void truc3(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
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

void truc2(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
{
	if (array_infix[i][1] != '\0' || is_digit(array_infix[i][0]))
		push_array(array_postfix, array_infix[i]);
	else if (array_infix[i][0] == '(')
		push(stack, (int)array_infix[i][0]);
}

void truc(char const **array_infix, char **array_postfix, my_struct_stack_t *stack, int i)
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
	char **array_postfix = create_array_postfix(size + 1);

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

	return (array_postfix);
}
