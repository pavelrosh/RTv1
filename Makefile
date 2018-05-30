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

NAME = rtv1
# SRC = main.c parse.c ray_trace.c
SRC = src/*.c
LIBS = libft/libft.a vec_op/veclib.a
HEADER = include/rtv1.h
FLAGS = -F /Library/Frameworks/ -framework SDL2 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib veclib
	gcc $(SRC) $(LIBS) $(FLAGS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	make fclean -C libft 
	make fclean -C vec_op 
	rm $(NAME)
lib:
	@make -C libft
	@make clean -C libft 

veclib:
	@make -C vec_op
	@make clean -C vec_op 
