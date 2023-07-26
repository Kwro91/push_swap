# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besalort <besalort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:14:38 by besalort          #+#    #+#              #
#    Updated: 2023/07/26 22:57:37 by besalort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/push_swap.c \
	./src/swap.c \
	./src/reverse_rotate.c \
	./src/rotate.c \
	./src/push.c \
	./src/load.c \
	./src/verif.c \
	./src/printpile.c \
	./src/algo.c \
	./src/algo_bis.c \
	./src/algo_re-order.c \
	./src/algo_sort_element.c \
	./src/algo_count.c \
	./src/update_indice.c \
	./src/mediane.c
	
LIBFT_PATH = ./src/libft/

LIBFT = $(LIBFT_PATH)libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

AR =  ar rcs

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = $(SRC:.c=.o)

$(NAME)	:	${OBJ}
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all	:	$(NAME)

clean :
		rm -rf $(OBJ)
		make clean -C $(LIBFT_PATH)

fclean :	clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re