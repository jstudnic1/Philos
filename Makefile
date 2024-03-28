# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstudnic <studnicka.jakub04@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 21:46:07 by jstudnic          #+#    #+#              #
#    Updated: 2024/03/27 21:46:08 by jstudnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc
CFLAGS	=	-g -pthread
#CFLAGS	=	-Wall -Wextra -Werror -g -pthread
RM		=	rm -rf
SANITIZER = -fsanitize=thread

SRC		=	$(addprefix src/, init.c main.c philoacts.c philocontrol.c timeutils.c utils.c)
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(SANITIZER) -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all



.PHONY: all clean fclean re
