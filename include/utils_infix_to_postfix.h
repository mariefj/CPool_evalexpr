#ifndef _UTILS_INFIX_TO_POSTFIX_H_
#define _UTILS_INFIX_TO_POSTFIX_H_

int	get_precedence(char op);
char	**create_str_array(int size);
char	*op_to_str(int op);
void	push_array(char **array, const char *elem);

#endif // _UTILS_INFIX_TO_POSTFIX_H_
