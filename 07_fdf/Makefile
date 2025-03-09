NAME = fdf

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -vf

SRC = 	fdf_center.c		\
		fdf_draw.c			\
		fdf_events.c		\
		fdf_file.c			\
		fdf_init.c			\
		fdf_main.c			\
		fdf_points.c		\
		fdf_str.c			\
		fdf_utils.c			\
		ft_split.c			\
		get_next_line.c		\
		get_next_line_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O3 -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
