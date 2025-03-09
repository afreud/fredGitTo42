NAME_S = server
NAME_C = client

BONUS_NAME_S = server_bonus
BONUS_NAME_C = client_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -O3
RM = rm -rvf

SRCS_S =	server.c		\
			mt_check.c		\
			mt_convert.c	\
			mt_utils.c

SRCS_C =	client.c		\
			mt_check.c		\
			mt_convert.c	\
			mt_utils.c

BONUS_SRCS_S =	bonus/server_bonus.c		\
				bonus/mt_check_bonus.c	\
				bonus/mt_convert_bonus.c	\
				bonus/mt_utils_bonus.c

BONUS_SRCS_C =	bonus/client_bonus.c		\
				bonus/mt_check_bonus.c	\
				bonus/mt_convert_bonus.c	\
				bonus/mt_utils_bonus.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

BONUS_OBJS_S = $(BONUS_SRCS_S:.c=.o)
BONUS_OBJS_C = $(BONUS_SRCS_C:.c=.o)

all: $(NAME_S) $(NAME_C)

bonus: $(BONUS_NAME_S) $(BONUS_NAME_C)


$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $^


$(BONUS_NAME_S): $(BONUS_OBJS_S)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME_C): $(BONUS_OBJS_C)
	$(CC) $(CFLAGS) -o $@ $^


clean:
	$(RM) *.o
	$(RM) bonus/*.o

fclean: clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)
	$(RM) $(BONUS_NAME_S)
	$(RM) $(BONUS_NAME_C)

re: fclean all

re_bonus: fclean bonus

.PHONY:
	all bonus clean fclean re
