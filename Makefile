NAME	=	eval_expr

SRCS	=	src/main.c			\
		src/eval_expr.c			\
		src/my_operation.c		\
		src/stack_op.c			\
		src/my_struct_func_ptr.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-g -Wall -Werror -W -Wextra -I./include -I./lib/my

LDFLAGS	=	-L./lib/my -lmy

CC	=	gcc

RM	=	rm -rf

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: clean fclean $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug test clear fclean re