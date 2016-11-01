# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smrabet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 15:48:45 by smrabet           #+#    #+#              #
#    Updated: 2016/10/24 16:03:38 by smrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = fdf.h

LIB = libft/

SRC = src/fdf.c \
	  src/list.c \
	  src/file.c \
	  src/img.c

GCC = gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) -L$(LIB) -lft
	@echo "\033[0;33;32mmake FDF"

%.o: %.c $(HEAD)
	@$(GCC) -c $<

clean:
	@make clean -C $(LIB)
	@rm -rf $(OBJ)
	@echo "\033[1;33;40mclean FDF"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)
	@echo "\033[1;31;40mfclean FDF"

re: fclean all
