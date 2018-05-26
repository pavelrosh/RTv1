# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 13:44:16 by proshchy          #+#    #+#              #
#    Updated: 2018/05/16 13:44:17 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = veclib.a
FLAGS = -Wall -Wextra -Werror
SRC = \
	vec_dot.c\
	vec_len.c\
	vec_norm.c\
	vec_scale.c\
	vec_sub.c\
	vec_sum.c\
	vec_rotx.c\
	vec_roty.c\
	vec_rotz.c\
	vec_rot.c
OBJ = \
	vec_dot.o\
	vec_len.o\
	vec_norm.o\
	vec_scale.o\
	vec_sub.o\
	vec_sum.o\
	vec_rotx.o\
	vec_roty.o\
	vec_rotz.o\
	vec_rot.o

HEADER = vec_op.h

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re