# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:33:04 by hzibari           #+#    #+#              #
#    Updated: 2024/02/26 13:40:49 by hzibari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT	=	libft/libft.a

LIBMLX		=	./lib/MLX42

SRCS	=	so_long.c \
			utils.c \
			map_checker.c \
			init_map.c \
			flood_fill_map.c \
			init_game.c \
			key_press_moves.c

OFILES	=	$(SRCS:.c=.o)

HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CC			=	cc
RM			=	-rm -f
CFLAGS		=	-Wall -Werror -Wextra
MLX_FLAGS	:=	-Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all: libmlx $(NAME)

libmlx:
	@if [ ! -d $(LIBMLX)/build ]; then\
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4;\
	fi

$(NAME): $(LIBFT) ${OFILES}
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(LIBS) $(MLX_FLAGS) $(HEADERS) -o $(NAME)


$(LIBFT):
	make -C ./libft

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		make fclean -C libft
		$(RM) $(OFILES)
		@rm -rf $(LIBMLX)/build
	
fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY: all clean fclean re libmlx