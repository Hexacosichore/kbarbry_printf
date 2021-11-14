# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:52:18 by kbarbry           #+#    #+#              #
#    Updated: 2021/11/04 20:41:34 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		=	\033[0m
BPurple		=	\033[1;35m
BGreen		=	\033[1;32m
UYellow		=	\033[3;33m

PART_1		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c

PART_2		=	ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

BONUS_PART	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJ			=	${PART_1:.c=.o} \
				${PART_2:.c=.o}

OBJ_BONUS	=	${BONUS_PART:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I.
NAME		=	libft.a

all:		${NAME}

%.o:%.c libft.h
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "${BPurple}[OBJ_FILE CREATED] :${RESET} ${<:.c=.o}${BGreen}\033[46G[✔]"

${NAME}:	${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "\n================================================"
	@echo "\n${BGreen}[DONE] ${RESET}all object files has been cleaned.${BGreen}\033[46G[✔]"

fclean: clean
	@rm -f ${NAME}
	@echo "${BGreen}[DONE] ${RESET}libft.a has been cleaned.${BGreen}\033[46G[✔]"
	@echo "\n${UYellow}\033[15G[EVERYTHING IS CLEAN]${RESET}\n"
	@echo "================================================\n"

bonus: ${NAME} ${OBJ} ${OBJ_BONUS}
	@ar rcs ${NAME} ${OBJ} ${OBJ_BONUS}
	@echo "\n${UYellow}\033[17G[BONUS ARE READY]${RESET}\n"
	@echo "================================================\n"

re:		fclean all
	@echo "\n${UYellow}\033[17G[LIBFT IS READY]${RESET}\n"
	@echo "================================================\n"

.PHONY: clean fclean all re