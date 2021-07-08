#ifndef _MY_STRUCT_STACK_H_
#define _MY_STRUCT_STACK_H_

typedef struct		my_struct_stack_s
{
			int top;
			int size;
			int* array;
}			my_struct_stack_t;

my_struct_stack_t	*stack_init(int size);
int 			is_empty(my_struct_stack_t *stack);
int 			pop(my_struct_stack_t *stack);
int 			peek(my_struct_stack_t *stack);
void 			push(my_struct_stack_t *stack, int elem);

#endif // _MY_STRUCT_STACK_H_
