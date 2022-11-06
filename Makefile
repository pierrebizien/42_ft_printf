PATH_LIBFT = ./libft/

PATH_SRCS = ./

NAME = libftprintf.a

SRCS = ${wildcard ${PATH_SRCS}*.c}

SRCS_LIBFT = ${wildcard ${PATH_LIBFT}*.c}

OBJS = ${SRCS:.c=.o}

OBJS_LIBFT = ${SRCS_LIBFT:.c=.o}

.c.o: 
	gcc -Wall -Werror -Wextra -c -I. -I ./libft $< -o ${<:.c=.o}

all: ${OBJS} ${OBJS_LIBFT}
	ar -rc -o ${NAME} ${OBJS} ${OBJS_LIBFT}

clean:
	rm -f ${OBJS} ${OBJS_LIBFT}

fclean: clean
	rm -f  ${NAME}

.PHONY: libft