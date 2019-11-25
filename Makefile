# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 15:48:45 by cgamora           #+#    #+#              #
#    Updated: 2019/11/20 15:51:34 by cgamora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./a.out
SRCS = ./*.c 
OBJS = ./*.o
HDR = ./fillit.h 
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all