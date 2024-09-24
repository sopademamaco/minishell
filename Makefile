# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 15:41:52 by davioliv          #+#    #+#              #
#    Updated: 2024/07/25 15:44:44 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main/main.c src/main/main_utils.c src/parser/tokenizer.c src/parser/tokenizer_utils.c src/parser/parser.c
NAME = minishell
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE = make -C
RM = rm -f
LIB = -L libft -lft

all:	${NAME}

$(NAME):	${OBJ}
	${MAKE} libft
	${CC} ${CFLAGS} ${OBJ} ${LIB} -lreadline -o ${NAME}

clean:
	${RM} ${OBJ}
	${MAKE} libft clean

fclean:	clean
	${RM} ${NAME}
	${MAKE} libft fclean

re:	fclean all

.PHONY: all clean fclean re
