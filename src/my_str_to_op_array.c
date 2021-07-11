#include <stdlib.h>

#include "my.h"
#include "my_str_to_op_array.h"
#include "my_struct_func_ptr.h"

int	get_nb_op(char const *str)
{
	int i = 0;
	int nb_op = 0;

	while (str[i] != '\0')
	{
		if ((is_digit(str[i]) || str[i] == ')') && is_valid_op(str[i + 1]))
		{
			nb_op++;
		}
		i++;
	}

	return (nb_op);
}

static int	get_nb_parenthesis(char const *str)
{
	int i = 0;
	int nb_p = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '(')
		{
			nb_p++;
		}
		i++;
	}

	return (nb_p * 2);
}

static char	*get_op(char **str, int *is_number)
{
	char *op = (char *)malloc(1 * sizeof(char));

	op[0] = '\0';
	op = my_append_c(op, **str);
	(*str)++;
	if (*is_number)
	{
		while (is_digit(**str))
		{
			op = my_append_c(op, **str);
			(*str)++;
		}
		*is_number = !(*is_number);
	}
	else
	{
		if (is_digit(**str) || (is_digit(*(*str + 1)) && **str == '-' && *(*str - 1) != ')'))
			*is_number = !(*is_number);
	}

	return (op);
}

char	**my_str_to_op_array(char *str)
{
	int i = 0;
	int is_number = is_digit(*str) || (*str == '-' && is_digit(*(str + 1)));
	int size = get_nb_op(str) * 2 + 1 + get_nb_parenthesis(str);
	char **array = (char **)malloc((size + 1) * sizeof(char *));

	if (array == NULL)
		return (NULL);

	while (*str != '\0' && i <= size)
	{
		while (*str == ' ')
		{
			str++;
		}
		array[i] = get_op(&str, &is_number);
		i++;
	}
	array[size] = NULL;

	return (array);
}