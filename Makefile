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
		src/ray_trace.c\
		src/validation.c

OBJ = $(SRC:.c=.o)
LIBS = libft/libft.a vec_op/veclib.a
HEADERS = -I ./include -I ./libft -I ./vec_op
HDR = include/rtv1.h
FLAGS = -Wall -Wextra -Werror
CGFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all: $(NAME)

$(NAME): libft/libft.a vec_op/veclib.a $(OBJ) $(HDR)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "Compailing RTv1 done\n"

.c.o: $(HDR)
	@gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C vec_op
	@rm -rf $(OBJ)
	@printf "All objects of RTv1 was deleted\n"

fclean:
	@make fclean -C libft
	@make fclean -C vec_op
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@printf "All objects and binary of RTv1 was deleted\n"

libft/libft.a:
	@make -C libft

vec_op/veclib.a:
	@make -C vec_op 

re: fclean all