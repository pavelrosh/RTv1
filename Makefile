# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 14:04:05 by proshchy          #+#    #+#              #
#    Updated: 2018/05/16 14:04:06 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = src/main.c\
	src/cylinder.c\
	src/light.c\
	src/cone.c\
	src/parse.c\
	src/plane.c\
	src/sphere.c\
	src/ray_trace.c
OBJ = $(SRC:.c=.o)
LIBS = libft/libft.a vec_op/veclib.a
HEADER = include/rtv1.h
CC_FLAGS = -Wall -Wextra
FLAGS = -F /Library/Frameworks/ -framework SDL2

all: $(NAME)

$(NAME): lib veclib $(OBJ)
	gcc $(CC_FLAGS) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

.c.o:
	gcc $(CC_FLAGS) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft 
	make fclean -C vec_op
	rm $(NAME)

lib:
	@make -C libft

veclib:
	@make -C vec_op

re: fclean all