# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:52:18 by kbarbry           #+#    #+#              #
#    Updated: 2021/11/14 16:39:44 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

SRC			= ft_printf.c
OBJ			= ${SRC:.c=.o}

SRC_TESTER	= test.c
OBJ_TESTER	= ${SRC_TESTER:.c=.o}
INCLUDES	= -I./includes
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
CLIBFT		= -L./libft -lft
HEADER		= ./ft_printf.h
NAME		= libftprintf.a

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}:
	@$(MAKE) bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)
	@echo "${GRN}[DONE]${RST} $(NAME) has created"

clean:
	@$(MAKE) clean -C ./libft
	@rm -f ${OBJ} 
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

test:
	${CC} ${CFLAGS} ${SRC_TESTER}  -L. -lftprintf -o tester
	./tester
	
re: fclean all