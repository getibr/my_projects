# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srigil <srigil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:21:30 by srigil            #+#    #+#              #
#    Updated: 2019/02/17 20:37:25 by srigil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FLAGS = -Werror -Wall -Wextra

all:
	gcc $(FLAGS) -o $(NAME) eval_expr.c eval_expr_2.c eval_expr_3.c eval_expr_4.c ft_atoi.c ft_calk.c \
	ft_putchar.c ft_putnbr_str.c ft_putnbr.c ft_putstr.c

clean:
	/bin/rm -f *.o

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

