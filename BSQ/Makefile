# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 14:12:19 by lminta            #+#    #+#              #
#    Updated: 2019/02/19 18:47:10 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = .

INC = .

FLAGS = -Wall -Werror -Wextra -o $(NAME)

FILES = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(FILES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
