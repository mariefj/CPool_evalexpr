#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct_stack.h"

my_struct_stack_t *stack_init(int size)
{
	my_struct_stack_t *stack = (my_struct_stack_t *)malloc(sizeof(my_struct_stack_t));

	if (!stack)
		return (NULL);

	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(stack->size * sizeof(int));

	if (!stack->array)
		return (NULL);

	return (stack);
}

int 	is_empty(my_struct_stack_t *stack)
{
	return (stack->top == -1);
}

int 	pop(my_struct_stack_t *stack)
{
	if (!is_empty(stack))
		return (stack->array[stack->top--]);

	return (84);
}

int 	peek(my_struct_stack_t *stack)
{
	return (stack->array[stack->top]);
}

void 	push(my_struct_stack_t *stack, int elem)
{
	stack->array[++stack->top] = elem;
}
