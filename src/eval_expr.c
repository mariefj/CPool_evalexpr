#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "eval_expr.h"
#include "my_str_to_op_array.h"
#include "infix_to_postfix.h"
#include "eval_postfix.h"

int	eval_expr(char *str)
{
	char **array_infix = my_str_to_op_array(str);
	char **array_postfix = infix_to_postfix((const char **)array_infix, my_tab_size((const char **)array_infix));
	int result = eval_postfix((const char **)array_postfix);

	free(array_infix);
	free(array_postfix);

	return (result);

}