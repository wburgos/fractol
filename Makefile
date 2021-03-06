#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 21:53:26 by wburgos           #+#    #+#              #
#    Updated: 2015/02/17 01:42:27 by wburgos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
SRCS = main.c draw.c events.c image.c triangle.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make re -C libft/
	@echo "Compiling fractol ..."
	@gcc -g3 -c $(SRCS) -I. -Ilibft/includes
	@gcc -o $(NAME) $(OBJ) -L/usr/X11/lib -Llibft -lmlx -lXext -lX11 -lft
	@echo "Done"

clean:
	@/bin/rm -f $(OBJ)
	@echo "Objects cleaned."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all
