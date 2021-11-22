# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:52:18 by kbarbry           #+#    #+#              #
#    Updated: 2021/11/18 12:43:12 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PART_1		=	ft_print_all.c \
				ft_printf.c

OBJ			=	${PART_1:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I.
NAME		=	libftprintf.a

all:		${NAME}

%.o:%.c ft_printf.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:		fclean all

.PHONY: clean fclean all re