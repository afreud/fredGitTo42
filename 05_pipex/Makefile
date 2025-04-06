NAME = pipex

BONUS = pipex_bonus

CC = cc

CFLAGS = -g -Werror -Wall -Wextra

RM = rm -vf

SRC = 	ft_getenv.c				\
		pipex.c					\
		pipex_cmds.c			\
		pipex_files.c			\
		pipex_main.c			\
		pipex_path.c			\
		pipex_split.c			\
		pipex_str.c				\
		pipex_utils.c

SRC_BONUS = bonus/ft_getenv_bonus.c				\
			bonus/get_next_line_bonus.c			\
			bonus/get_next_line_utils_bonus.c	\
			bonus/pipex_bonus.c					\
			bonus/pipex_cmds_bonus.c			\
			bonus/pipex_files_bonus.c			\
			bonus/pipex_main_bonus.c			\
			bonus/pipex_path_bonus.c			\
			bonus/pipex_split_bonus.c			\
			bonus/pipex_str_bonus.c				\
			bonus/pipex_utils_bonus.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

bonus: $(BONUS)

clean:
	$(RM) *.o bonus/*.o

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY:
	all bonus clean fclean re
