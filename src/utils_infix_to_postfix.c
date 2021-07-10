#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "utils_infix_to_postfix.h"

int	get_precedence(char op)
{
	if (op == '+' || op == '-')
		return (1);

	if (op == '*' || op == '/' || op == '%')
		return (2);

	return (-1);
}

char	**create_str_array(int size)
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
