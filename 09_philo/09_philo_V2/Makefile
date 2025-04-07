NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
TSAN = -fsanitize=thread -g

RM = rm -rvf

SRC =	main_philo.c	\
		philo.c			\
		philo_utils.c

%.o: %.c
	$(CC) $(TSAN) $(CFLAGS) -o $@ -c $^

OBJ = $(CC:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
