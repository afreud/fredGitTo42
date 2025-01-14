NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -vf

SRCS =	ft_split.c				\
		pushswap_check.c		\
		pushswap_init.c			\
		pushswap_lst.c			\
		pushswap_main.c			\
		pushswap_order.c		\
		pushswap_push.c			\
		pushswap_rank.c			\
		pushswap_rot.c			\
		pushswap_rrot.c			\
		pushswap_sort_all.c		\
		pushswap_sort_one.c		\
		pushswap_sort_tiny.c	\
		pushswap_swp.c			\
		pushswap_to_send.c		\
		pushswap_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re

