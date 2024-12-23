NAME= pipex

CC= cc

CFLAGS= -Werror -Wall -Wextra

RM = rm -f

SRC = 	ft_getenv.c				\
		get_next_line.c			\
		get_next_line_utils.c	\
		pipex.c					\
		pipex_cmds.c			\
		pipex_files.c			\
		pipex_main.c			\
		pipex_path.c			\
		pipex_split.c			\
		pipex_str.c				\
		pipex_utils.c

SRC_BONUS =


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $^

bonus: $(OBJ_BONUS)
	$(CC) $( CFLAGS) -o $@ -c $^

all: $(NAME)

clean:
	$(RM) *.o

fclean:
	$(RM) $(NAME) clean

re:
	fclean all

.PHONY:
	bonus all clean fclean re
