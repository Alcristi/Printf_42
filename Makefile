NAME = libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c

OBJS	=	${SRCS:.c=.o}

INCLUDE = ft_printf.h

all: ${NAME}

${NAME}: ${OBJS} ${INCLUDE}
	@ar rcs ${NAME} ${OBJS}

clean :
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
