SRCS	= *.c

LIB_PATH	= ./libft

OBJ	= *.o

RM		= rm -f

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra -c

all:		$(NAME)

$(NAME):	${SRCS} $(LIB_PATH)/*.c ft_printf.h
			make re -C $(LIB_PATH)
			gcc $(CFLAGS) $(SRCS)
			ar rc $(NAME) $(OBJ) $(LIB_PATH)/*.o
			ranlib $(NAME)

clean:
			$(RM) $(OBJ)
			make clean -C $(LIB_PATH)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIB_PATH)

re:			fclean all

.PHONY:		all clean fclean re
