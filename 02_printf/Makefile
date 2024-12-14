# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frdurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 17:34:38 by frdurand          #+#    #+#              #
#    Updated: 2024/11/22 10:15:24 by frdurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFlAGS = -Wall -Werror -Wextra

CFILES = 	ft_printf.c		\
			ft_putadr.c 	\
			ft_putchar.c	\
			ft_puthex.c		\
			ft_putnbr.c		\
			ft_putstr.c		\
			ft_putunbr.c	\
			ft_strlen.c

OFILES =  $(CFILES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $^

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES) 

all: $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY :
	all clean fclean re
