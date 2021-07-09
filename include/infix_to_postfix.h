#ifndef _INFIX_TO_POSTFIX_H_
#define _INFIX_TO_POSTFIX_H_

int	get_precedence(char op);
char	**create_array_postfix(int size);
char	*op_to_str(int op);
void	push_array(char **array, const char *elem);
char	**infix_to_postfix(const char **array_infix, int size);

//#define DEBUG 1

#endif // _INFIX_TO_POSTFIX_H_
