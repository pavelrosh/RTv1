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

OBJ = $(SRC:.c=.o)
HEADER = vec_op.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@printf "Compailing vec_op.a done\n"

.c.o: $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@printf "All objects of vector operation library was deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "Vector operation library is clean\n"

re: fclean all

.PHONY: all clean fclean re