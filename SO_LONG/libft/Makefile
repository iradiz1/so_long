# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:33:04 by hzibari           #+#    #+#              #
#    Updated: 2024/02/07 10:22:27 by hzibari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	ft_atoi.c \
 			ft_bzero.c \
 			ft_calloc.c \
 			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putstr_fd.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_putnbr_fd.c \
			ft_putchar_fd.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putendl_fd.c \
			ft_substr.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_printf.c \
			numbr_printer.c \
			unsigned_printer.c \
			hexa_printer.c \
			adress_printer.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			get_next_line.c

OFILES	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OFILES)
		ar -rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus