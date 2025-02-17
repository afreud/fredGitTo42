NAME_S = server
NAME_C = client

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rvf
INCLUDE = -I include

SRCS_S =	server.c		\
			mt_check.c		\
			mt_convert.c	\
			mt_utils.c

SRCS_C =	client.c		\
			mt_check.c		\
			mt_convert.c	\
			mt_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)

re: fclean all

.PHONY:
	all clean fclean re
