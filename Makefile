# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:52:18 by kbarbry           #+#    #+#              #
#    Updated: 2021/11/17 10:49:05 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		=	\033[0m
BPurple		=	\033[1;35m
BGreen		=	\033[1;32m
UYellow		=	\033[3;33m

PART_1		=	ft_print_all.c \
				ft_printf.c

OBJ			=	${PART_1:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I.
NAME		=	libftprintf.a

all:		${NAME}

%.o:%.c ft_printf.h
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "${BPurple}[OBJ_FILE CREATED] :${RESET} ${<:.c=.o}${BGreen}\033[46G[✔]"

${NAME}:	${OBJ}
	@ar -rcs ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}
	@echo "\n================================================"
	@echo "\n${BGreen}[DONE] ${RESET}all object files has been cleaned.${BGreen}\033[46G[✔]"

fclean: clean
	@rm -f ${NAME}
	@echo "${BGreen}[DONE] ${RESET}printf.a has been cleaned.${BGreen}\033[46G[✔]"
	@echo "\n${UYellow}\033[15G[EVERYTHING IS CLEAN]${RESET}\n"
	@echo "================================================\n"

re:		fclean all
	@echo "\n${UYellow}\033[17G[PRINTF IS READY]${RESET}\n"
	@echo "================================================\n"

.PHONY: clean fclean all re