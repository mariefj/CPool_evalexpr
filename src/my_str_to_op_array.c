#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_str_to_op_array.h"
#include "my_struct_func_ptr.h"

#include <stdio.h>


int	is_digit(char digit)
{
	return ((digit >= '0' && digit <= '9'));
}

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

static char	*my_append_c(char *str, char c)
{
	int i = 0;
	int len = my_strlen(str) + 2;
	char *new_str = (char *)malloc(len * sizeof(char));

	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);

	return (new_str);
}

static char	*get_op(char **str, int *is_number)
{
	char *op = (char *)malloc(1 * sizeof(char));

	op[0] = '\0';
	if (*is_number)
	{
		op = my_append_c(op, **str);
		(*str)++;
		while (is_digit(**str))
		{
			op = my_append_c(op, **str);
			(*str)++;
		}
		*is_number = !(*is_number);
	}
	else
	{
		op = my_append_c(op, **str);
		(*str)++;
		if (is_digit(**str) || (is_digit(*(*str + 1)) && **str == '-' && *(*str - 1) != ')'))
			*is_number = !(*is_number);
	}

	return (op);
}

char	**my_str_to_op_array(char *str)
{
	int i = 0;
	int is_number = is_digit(*str) || (*str == '-' && is_digit(*(str + 1)));
	printf("is number = %d\n", is_number);
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
	array[size + 1] = NULL;

	return (array);
}