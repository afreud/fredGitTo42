
(LIB) = libft.a

(CC) = gcc
(CFLAGS) = -Wall -Wextra -Werror

(AR) = ar
(ARFLAGS) = -rcs

(RM) = rm -f

(SRCS) =	ft_split.c		\
			ft_strjoin.c	\
			ft_strmapi.c	\
			ft_strtrim.c

(OBJS) = $(SRCS:.c=.o)

all: $(LIB) clean

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

%.o: %.c
	$(cc) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean:
	clean $(RM) $(LIB)

re:
	fclean $(LIB)

.PHONY:
	all clean fclean re
