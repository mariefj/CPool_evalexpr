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

char	**infix_to_postfix(char const **array_infix, int size)
{
	int i = 0;
	my_struct_stack_t *stack = stack_init(size);
	char **array_postfix = create_array_postfix(size + 1);

	//my_print_array(array_infix);
	array_postfix[0] = NULL;
	my_print_array((const char **)array_infix);
	while (i < size)
	{
		#ifdef DEBUG
		//printf("array_infix[%d] = %s\n", i, array_infix[i]);
		#endif
		if (array_infix[i][1] != '\0' || is_digit(array_infix[i][0]))
		{
			push_array(array_postfix, array_infix[i]);
		}
		else if (array_infix[i][0] == '(')
		{
			push(stack, (int)array_infix[i][0]);
		}
		else if (array_infix[i][0] == ')')
		{
			printf("------start------ 1er while\n");
			printf("array[%d] = %s\n", i, array_infix[i]);
			while (!is_empty(stack) && peek(stack) != '(')
			{
				printf("pop = %c\n", peek(stack));
				push_array(array_postfix, op_to_str(pop(stack)));
			}
			pop(stack);
			printf("------stop------ 1er while\n");
		}
		else
		{
			printf("------start------ 2e while\n");
			printf("array[%d] = %s\n", i, array_infix[i]);
			while (!is_empty(stack) && get_precedence(array_infix[i][0]) < get_precedence(peek(stack)))
			{
				printf("pop = %c\n", peek(stack));
				push_array(array_postfix, op_to_str(pop(stack)));
			}
			push(stack, array_infix[i][0]);
			printf("------stop------ 2e while\n");
		}
		i++;
	}
	printf("------start------ end\n");
	while (!is_empty(stack))
	{
		printf("pop = %c\n", peek(stack));
		push_array(array_postfix, op_to_str(pop(stack)));
		i++;
	}
	printf("------stop------ end\n");

	my_print_array((const char **)array_postfix);

	return (array_postfix);
}
