#ifndef _MY_STRUCT_FUNC_PTR_H_
#define _MY_STRUCT_FUNC_PTR_H_

#define OPERTOR_NB 5

typedef struct	my_struct_func_ptr_s
{
		char	op;
		int	(*operand)(int, int);
}		my_struct_func_ptr_t;

void set_up_struct(my_struct_func_ptr_t *ops);
int do_op(char op, int val1, int val2);

#endif // _MY_STRUCT_FUNC_PTR_H_
