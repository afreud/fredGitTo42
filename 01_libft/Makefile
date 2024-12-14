# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frdurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:11:48 by frdurand          #+#    #+#              #
#    Updated: 2024/11/21 15:11:53 by frdurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strmapi.c	\
		ft_strtrim.c	\
		ft_itoa.c		\
		ft_substr.c

CBONUS =	ft_lstadd_back_bonus.c	\
			ft_lstadd_front_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstdelone_bonus.c	\
			ft_lstiter_bonus.c		\
			ft_lstlast_bonus.c		\
			ft_lstmap_bonus.c		\
			ft_lstnew_bonus.c		\
			ft_lstsize_bonus.c

OFILES = $(CFILES:.c=.o)

OBONUS = $(CBONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME) :	$(OFILES)
			ar -rcs $(NAME) $(OFILES)

bonus :		$(OBONUS)
			ar -rcs $(NAME) $(OBONUS)

all : $(NAME) 

clean :
			rm -f *.o

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re bonus

